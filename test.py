import fileinput
from random import *
from tkinter import *
from time import *
import tkinter

def draw_rooms(rooms):
    global scale
    global start
    global end
    colors = ['lime', 'red', 'yellow']
    for key in rooms:
        rooms[key][0] = rooms[key][0] * scale
        rooms[key][1] = rooms[key][1] * scale
        x = rooms[key][0]
        y = rooms[key][1]
        if (key == start):
            f = 0
        elif (key == end):
            f = 1
        else:
            f = 2
        canvas.create_oval(x, y, x+scale, y+scale, fill=colors[f], outline='black', width=2)
        canvas.create_text(x + scale/2, y + scale/2, anchor=W, font="Purisa", text=key)
    canvas.create_text(5, size - 80, anchor=W, font=("Courier", 30), text="start room - ")
    canvas.create_text(230, size - 80, anchor=W, fill="green", font=("Purisa", 30), text=start)
    canvas.create_text(5, size - 50, anchor=W, font=("Courier", 30), text="end room - ")
    canvas.create_text(230, size - 50, anchor=W, fill="red", font=("Purisa", 30), text=end)
    root.update()
    sleep(0.5)


def draw_links(rooms, links):
    global scale
    for el in links:
        f = rooms[el[0]]
        s = rooms[el[1]]
        canvas.create_line(f[0] + scale/2, f[1] + scale/2, s[0] + scale/2, s[1] + scale/2)

def read_map(rooms, links, action):
    global num
    global start
    global end
    global num_room
    f = 0
    # num = input()
    for line in fileinput.input():
        line = line.rstrip()
        #print(line)
        if line == "KARAMBA!":
            break
        elif line == "ERROR":
            print("Something wrong")
            exit()
        elif line != "" and line[0] == 'L':
            action.append(line)
        elif line == "##start":
            f = 1
        elif line == "##end":
            f = 2
        elif line == "" or line[0] == '#':
            continue
        elif num_room == 0 and num == "":
            num = line
        elif line.find(' ') != -1:
            num_room += 1
            new = line.split(maxsplit=1)
            coordi = new[1].split(' ')
            coordi[0] = (int(coordi[0])  + randint(10,20))
            coordi[1] = (int(coordi[1])  + randint(10,20))
            rooms[new[0]] = coordi
            if f == 1:
                start = new[0]
                f = 0
            if f == 2:
                end = new[0]
                f = 0
        elif line.find('-') != -1:
            new = line.split('-')
            links.append(new)
        

def draw_ant(key, number):
    global rooms
    global img
    global scale
    colors = ['aqua', 'blue', 'fuchsia', 'green', 'maroon', 'orange',
                  'pink', 'purple', 'red','yellow', 'violet', 'indigo', 'chartreuse', 'lime']
    x = rooms[key][0]
    y = rooms[key][1]
    ant = canvas.create_rectangle(x , y , x + scale, y + scale, outline=colors[number], fill=colors[number], width=1, tag='ant')
    #canvas.create_image(x+10, y+10, anchor=NW, image=img, tag='ant')


def draw_action(action):
    global num
    global start
    global speed
    global size
    global end

    f = 0
    newa = "L" + num
    draw_ant(start, 11)
    root.update()
    sleep(speed)
    i = 1
    # canvas.create_text(5, size - 80, anchor=W, font=("Purisa", 30), text="start room - ")
    # canvas.create_text(150, size - 80, anchor=W, fill="green", font=("Purisa", 30), text=start)
    # canvas.create_text(5, size - 50, anchor=W, font=("Purisa", 30), text="end room - ")
    # canvas.create_text(150, size - 50, anchor=W, fill="red", font=("Purisa", 30), text=end)
    for value in action:
        canvas.delete('ant')
        canvas.create_text(5, size - 25, anchor=W, tag='ant', font="Courier", text="iterations: " + (str)(i))
        canvas.create_text(5, size - 5, anchor=W, tag='ant', font="Courier", text="speed: " + (str)(2.5 - speed))
        i = i + 1
        if (f == 0):
            if (value.find(newa) != -1):
                f = 1
            else:
                draw_ant(start, 11)
        new = value.split(' ')
        for value1 in new:
            new1 = value1.split('-')
            draw_ant(new1[1], int(new1[0][-1]))
        root.update()
        #Button(root, text="Quit", command=root.destroy).pack()
        sleep(speed)

def speedd():
    global speed
    if (speed > 0.5):
        speed = speed - 0.5
    #print(speed)

rooms = {}
links = []
action = []
num = ""
start = ""
end = ""
size = 1000

speed = 2
num_room = 0
root = Tk()
canvas = Canvas(root, width=size * 2 - 300, height=size)
canvas.pack()
#img = PhotoImage(file="py/smoking_ant.png")
#img = img.subsample(7)
#canvas.create_image(0, 0, anchor=NW, image=img)
read_map(rooms, links, action)
if num_room < 10:
    scale = 30
elif num_room < 50:
    scale = 10
else:
    scale = 5
draw_rooms(rooms)
draw_links(rooms, links)
print(action)

#допустим, я знаю start и end уже
#движение одного муравья
Button(root, text="Speed", command=speedd).pack()
Button(root, text="Quit", command=root.destroy).pack()
canvas.create_text(size * 2 - 450, size - 5, anchor=W, font="Courier", text=u"\u00A9" + " dholiday, mkami")

root.update()
draw_action(action)


sleep(5)
root.destroy()
#input('Press ENTER to exit')
#Button(root, text="Speed", command=speedd).pack()
#Button(root, text="Quit", command=root.destroy).pack()
root.mainloop()
