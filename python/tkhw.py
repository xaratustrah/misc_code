#Example (Hello, World):
import tkinter
 
tk = tkinter.Tk()
frame = tkinter.Frame(tk, relief="ridge", borderwidth=2)
frame.pack(fill="both",expand=1)
label = tkinter.Label(frame, text="Hallo Welt!")
label.pack(expand=1)
button = tkinter.Button(frame,text="OK",command=tk.destroy)
button.pack(side="bottom")
 
tk.mainloop()
