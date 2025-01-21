import serial
from collections import deque
from copy import deepcopy
from time import sleep

# Arduino 串列通訊設定
COM_PORT = 'COM7'
BAUD_RATES = 9600
ser = serial.Serial(COM_PORT, BAUD_RATES)

n = 11  # 房間數量

# 初始化獎勵矩陣
R = [[-1 for x in range(n)] for y in range(n)]

# 設定初始路徑連接
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

def bfs_shortest_path(graph, start, target):
    """使用 BFS 尋找最短路徑"""
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

# 主程式
num_blocked_rooms = 0
starting_points = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J']
results = {}
received_letters = []

while True:
    num_blocked_rooms += 1
    result = ""
    
    # 從 Arduino 接收阻擋房間信號
    blocked_room = ser.read().decode()

    if blocked_room == "e":
        break

    # 檢查是否重複接收
    if blocked_room in received_letters:
        continue

    # 計算被阻擋房間的索引
    blocked_index = ord(blocked_room) - 65

    # 更新 R 矩陣，阻擋相關路徑
    if blocked_index >= 0 and blocked_index < n:
        for j in range(n):
            R[blocked_index][j] = -1
            R[j][blocked_index] = -1

        received_letters.append(blocked_room)

        # 對每個起點尋找路徑
        current_starting_points = deepcopy(starting_points)

        while current_starting_points:
            start_room = current_starting_points.pop(0)
            start_index = ord(start_room) - 65

            print(f'起點 {num_blocked_rooms}: {start_room}')
            print(f'最佳路徑 {num_blocked_rooms}: ', end='')

            # 使用 BFS 尋找最短路徑
            shortest_path = bfs_shortest_path(R, start_index, n - 1)

            if shortest_path:
                path_str = "".join(chr(node + 65) for node in shortest_path)
                print(path_str)
                result += path_str

        # 儲存並顯示結果
        results[f'最佳路徑 {num_blocked_rooms}'] = result
        print(f"最終結果 {num_blocked_rooms}:", results[f'最佳路徑 {num_blocked_rooms}'])

        # 發送結果給 Arduino
        ser.write(result.encode())
        sleep(0.5)