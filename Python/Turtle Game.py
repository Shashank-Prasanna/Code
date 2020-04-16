#!/bin/python3
from turtle import *
from random import randint
speed(2000)
penup()
backward(100)
for step in range(11):
  write(step, align='center')
  penup()
  right(90)
  forward(20)
  pendown()
  forward(150)
  penup()
  backward(170)
  left(90)
  forward(20)

red = Turtle()
red.color('red')
red.shape('turtle')

blue = Turtle()
blue.color('blue')
blue.shape('turtle')

green = Turtle()
green.color('green')
green.shape('turtle')

yellow = Turtle()
yellow.color('gold')
yellow.shape('turtle')

red.penup()
red.goto(-110, -30)
red.pendown()
blue.penup()
blue.goto(-110, -50)
blue.pendown()
green.penup()
green.goto(-110, -70)
green.pendown()
yellow.penup()
yellow.goto(-110, -90)
yellow.pendown()


for turn in range(78):
  red.forward(randint(1,5))
  blue.forward(randint(1,5))
  green.forward(randint(1,5))
  yellow.forward(randint(1,5))




