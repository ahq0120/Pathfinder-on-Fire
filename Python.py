import random
from collections import deque
from copy import deepcopy
import serial
from time import sleep
import sys


COM_PORT = 'COM4'
BAUD_RATES = 9600
ser = serial.Serial(COM_PORT, BAUD_RATES)

iterations = 10000
n = 11
lr = 0.8
gamma = 0.9  # 

# 1
Q = [[0 for x in range(n)] for y in range(n)]
R = [[-1 for x in range(n)] for y in range(n)]

# 1
R[0][2] = R[0][4] = 0
R[1][2] = 0
R[2][0] = R[2][1] = R[2][7] = 0
R[3][4] = 0
R[4][0] = R[4][3] = R[4][9] = 0
R[5][6] = 0
R[6][5] = R[6][7] = 0
R[6][10] = 100
R[7][2] = R[7][6] = R[7][8] = 0
R[8][7] = R[8][9] = 0
R[9][4] = R[9][8] = 0
R[9][10] = 100
R[10][6] = R[10][9] = 0
R[10][10] = 100

def choose_action(state):
    if random.uniform(0, 1) < 0.9:
        return Q[state].index(max(Q[state]))
    else:
        return random.randint(0, n - 1)

def update_q_table(current_state, action, reward, next_state):
    max_q_value = max(Q[next_state])
    Q[current_state][action] = Q[current_state][action] + lr * (reward + gamma * max_q_value - Q[current_state][action])

# 1
for s in range(iterations):
    starter = [i for i in range(n)]
    start = random.choice(starter)
    current_state = start

    while current_state != n - 1:
        action = choose_action(current_state)

        reward = R[current_state][action]
        next_state = action

        update_q_table(current_state, action, reward, next_state)

        current_state = next_state

for i in range(n):
    for j in range(n):
        Q[i][j] = int(Q[i][j])

for i in range(n):
    for j in range(n):
        print(Q[i][j], end=' ')
    print()

def bfs_shortest_path(graph, start, target):
    queue = deque([(start, [])])
    visited = set()

    while queue:
        node, path = queue.popleft()
        visited.add(node)

        if node == target:
            return path + [node]

        for neighbor in range(len(graph)):
            if graph[node][neighbor] > -1 and neighbor not in visited:
                queue.append((neighbor, path + [node]))

    return None

num_blocked_rooms = 0
starting_points = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J']
result = ""

while True:
    #result = ""  
    blocked_room = input(f'封閉的第 {num_blocked_rooms + 1} 間房間: ')
    if blocked_room == "e":
        break

    blocked_index = ord(blocked_room) - 65

    for j in range(n):
        R[blocked_index][j] = -1
        R[j][blocked_index] = -1

    num_blocked_rooms += 1

    # 
    current_starting_points = deepcopy(starting_points)

    while current_starting_points:
        start_room = current_starting_points.pop(0)
        start_index = ord(start_room) - 65

        print(f'起點 {num_blocked_rooms}: {start_room}')

        print(f'最佳路徑 {num_blocked_rooms}: ', end='')

        shortest_path = bfs_shortest_path(R, start_index, n - 1)

        if shortest_path:
            path_str = "".join(chr(node + 65) for node in shortest_path)
            print(path_str)
            result += path_str  
        else:
            print("無法找到到達終點的路徑")

    
    print("最終結果:", result)


    
    ser.write(result.encode())
    sleep(0.5)              
        