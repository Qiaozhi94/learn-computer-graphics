
px = -3
py = 4

vx = 5
vy = -2

x = float(input("要判断的点的横坐标是"))
y = float(input("要判断的点的纵坐标是"))


a = (vx - px)*(vx - px) + (vy - py)*(vy - py)
ax = (vx - px)/(a ** 0.5)
ay = (vy - py)/(a ** 0.5)

b = (x - px) * ax + (y - py) * ay

if b > 0:
    print("该点在NPC前方")
if b < 0:
    print("该点在NPC后方")
if b == 0:
    print("该点在NPC一侧")

