import turtle

# Screen Configuration
WIDTH, HEIGHT = 1080, 520
screen = turtle.Screen()
screen.setup(WIDTH, HEIGHT)
screen.screensize(3 * WIDTH, 3 * HEIGHT)
screen.bgcolor('black')
screen.delay(0)

# "Pencil" configuration
pencil = turtle.Turtle()
pencil.pensize(3)
pencil.speed(1)
pencil.setpos(-WIDTH // 3, HEIGHT // 12)
pencil.color('green')

# Fractal specific configuration
step = 20
angle = 90

sequence = "-+-+F-F-F+F+-F+F+F-F-F+F+F-+F+F-F-F+-F-+-F+F+F-F-+F-F-F+F+F-F-F+-F-F+F+F-+F+-F+F+F-F-+F-F-F+F+F-F-F+-F-F+F+F-+-F-+F-F-F+F+-F+F+F-F-F+F+F-+F+F-F-F+-+F+-+-F+F+F-F-+F-F-F+F+F-F-F+-F-F+F+F-+F+-+F-F-F+F+-F+F+F-F-F+F+F-+F+F-F-F+-F-+F-F-F+F+-F+F+F-F-F+F+F-+F+F-F-F+-+F+-F+F+F-F-+F-F-F+F+F-F-F+-F-F+F+F-+-F-+-F+F+F-F-+F-F-F+F+F-F-F+-F-F+F+F-+F+-+F-F-F+F+-F+F+F-F-F+F+F-+F+F-F-F+-F-+F-F-F+F+-F+F+F-F-F+F+F-+F+F-F-F+-+F+-F+F+F-F-+F-F-F+F+F-F-F+-F-F+F+F-+-+F+-+F-F-F+F+-F+F+F-F-F+F+F-+F+F-F-F+-F-+-F+F+F-F-+F-F-F+F+F-F-F+-F-F+F+F-+F+-F+F+F-F-+F-F-F+F+F-F-F+-F-F+F+F-+-F-+F-F-F+F+-F+F+F-F-F+F+F-+F+F-F-F+-+-"

for char in sequence:
    if char == "F":
        pencil.forward(step)
    if char == "-":
        pencil.left(angle)
    if char == "+":
        pencil.right(angle)

# Necessary! Or the screen it will close instantly.
screen.exitonclick()