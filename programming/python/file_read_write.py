f = open ("file_read_write.py", "r") # open for reading
print(f.read())

f = open("file_read_write.txt", "a") # Append to an existing file
f.write("New content")
f.close()

f = open("file_read_write2.txt", "w") # Creating and writing to a new file
f.write("Only new content here");
f.close()
