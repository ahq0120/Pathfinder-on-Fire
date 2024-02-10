# Pathfinder on Fire

**世新資管畢業專題**
**組長：林旻毅**

![專案封面圖](https://github.com/ahq0120/image/blob/main/Model.png)

## 功能

解決大型賣場、車站等路線複雜場所的逃生問題

## 硬體

> WS2812-B LED燈條

![WS2812-B](https://github.com/ahq0120/image/blob/main/WS2812B.png)

> MQ-2煙霧感測器

![MQ-2](https://github.com/ahq0120/image/blob/main/MQ2.png)

> Arduino

![Arduino](https://github.com/ahq0120/image/blob/main/Arduino.jpg)

## 使用說明

Python 版本建議為：`3.6` 以上...

### 先後開啟Arduino以及Python

![Arduinoc](https://github.com/ahq0120/image/blob/main/Arduinoc.png)
![Pythonc](https://github.com/ahq0120/image/blob/main/Pythonc.png)

### 煙霧偵測

> 發生火災時，偵測火原位置

![smoke0](https://github.com/ahq0120/image/blob/main/smoke0.png)

### 計算最短路徑

> Python計算每個房間離出口的最短路徑

![q0](https://github.com/ahq0120/image/blob/main/q0.png)

### 路徑顯示

將每個房間內的人指引至出口

### 煙霧偵測

火勢持續蔓延時，繼續偵測火原位置

> 與前一次不同房間發生火災

![smoke](https://github.com/ahq0120/image/blob/main/smoke1.png)

### 重新計算最短路徑

> Python重新計算包含舊火源的最短路徑

![q1](https://github.com/ahq0120/image/blob/main/q1.png)

### 路徑顯示

將每個房間內的人指引至出口

## 專案技術

- Python
- C++