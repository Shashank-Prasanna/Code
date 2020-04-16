from guizero import App, Text, TextBox, PushButton,Slider,Picture
app = App(title="Hello World")
welcome_message = Text(app, text="Welcome to my app", font="Mono Sans", color="navyblue")

my_name = TextBox(app)

def saymyname():
    welcome_message.value = my_name.value

update_text = PushButton(app, command=saymyname, text="Display my name")

def changetextsize(slider_value):
    welcome_message.size = slider_value
text_size = Slider(app, command=changetextsize, start=10, end=80)

my_cat = Picture(app, image="cat.gif")

app.display()
