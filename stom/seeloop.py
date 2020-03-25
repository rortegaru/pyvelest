import time
import stom

startime=time.time()
for i in range(10000):
	stom.r_velest()
finishtime=time.time()

elapsedtime=finishtime-startime

print(elapsedtime)
