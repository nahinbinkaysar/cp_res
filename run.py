import os, sys, time

name = ""

# https://codeforces.com/contest/1833/problem/C
# https://codeforces.com/problemset/problem/1832/C


link = sys.argv[1].split("/")

if link[0] == "https:":
	if(link[3] == "problemset"): name = link[5] + link[6]
	elif(link[3] == "contest"): name = link[4] + link[6]
	file = name + ".cpp"
else:
	file = sys.argv[1] + ".cpp"

os.system(f"if not exist {file} copy template.cpp {file}")
os.system("code " + file)

while True:
	cmd = input()
	if cmd == "c":
		print("_", end="")
		os.system("g++ " + file)
		print("✓")
	elif cmd == "a":
		os.system("a")
		print("----")
	elif cmd == "cls":
		os.system("cls")
	elif cmd == "del":
		os.system("del " + file)
		break
	elif cmd == "x":
		break
	elif cmd == "date":
		f = open(file, "a")
		ctime = os.path.getctime(file)
		mtime = os.path.getmtime(file)
		cdate = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(ctime))
		mdate = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(mtime))
		f.write("\n//" + cdate + "\n//" + mdate)
		f.close()

