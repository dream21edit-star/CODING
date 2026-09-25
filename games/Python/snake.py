import turtle as t
import random
import time

d = 0.1
s = 0
hs = 0
run = True

# screen
sc = t.Screen()
sc.title("Snake Game")
sc.bgcolor("#add8e6")
sc.setup(width=600, height=600)
sc.tracer(0)

# snake head
h = t.Turtle()
h.shape("square")
h.color("white")
h.penup()
h.goto(0, 0)
h.direction = "Stop"

#food
f = t.Turtle()
f.shape(random.choice(["circle", "square", "triangle"]))
f.color(random.choice(["red", "green", "black"]))
f.penup()
f.goto(0, 100)

#scoreboard
p = t.Turtle()
p.hideturtle()
p.penup()
p.goto(0, 250)
p.write("Score: 0 High Score: 0", align="center", font=("candara", 24, "bold"))

def up():
    if h.direction != "down":
        h.direction = "up"
def down():
    if h.direction != "up":
        h.direction = "down"
def left():
    if h.direction != "right":
        h.direction = "left"
def right():
    if h.direction != "left":
        h.direction = "right"

def move():
    if h.direction == "up":
        h.sety(h.ycor() + 20)
    elif h.direction == "down":
        h.sety(h.ycor() - 20)
    elif h.direction == "left":
        h.setx(h.xcor() - 20)
    elif h.direction == "right":
        h.setx(h.xcor() + 20)

sc.listen()

sc.onkeypress(up, "Up")
sc.onkeypress(down, "Down")
sc.onkeypress(left, "Left")
sc.onkeypress(right, "Right")

seg = []

while run:
    try:
        sc.update()

        # wall collision
        if abs(h.xcor()) > 290 or abs(h.ycor()) > 290:
            time.sleep(1)
            h.goto(0, 0)
            h.direction= "Stop"

            for segment in seg:
                segment.goto(1000, 1000)
            seg.clear()

            s = 0
            d = 0.1
            p.clear()

            p.write(f"Score: {s} High Score: {hs}", align="center", font=("candara", 24, "bold"))
                                                                          
        # food collision
        if h.distance(f) < 20:
            f.goto(random.randint(-270, 270), random.randint(-270, 270))
            new_seg = t.Turtle()
            new_seg.shape("square")
            new_seg.color("orange")
            new_seg.penup()
            seg.append(new_seg)
            d -= 0.001
            s += 10

            if s > hs:
                hs = s
            p.clear()
            p.write(f"Score: {s} High Score: {hs}", align="center", font=("candara", 24, "bold"))

        # move body
        for i in range(len(seg) - 1, 0, -1):
            x = seg[i-1].xcor()
            y = seg[i-1].ycor()
            seg[i].goto(x,y)
        if seg:
            seg[0].goto(h.xcor(), h.ycor())
        move()

        for segment in seg:
            if segment.distance(h) < 20:
                time.sleep(1)
                h.goto(0, 0)
                h.direction = "Stop"

                for segment in seg:
                    segment.goto(1000, 1000)
                seg.clear()

                s = 0
                d = 0.1
                p.clear()
                p.write(f"Score: {s} High Score: {hs}", align="center", font=("candara", 24, "bold"))
        
        time.sleep(d)

    except t.Terminator:
        run = False