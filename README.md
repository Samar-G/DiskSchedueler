# DiskSchedueler
Assume that a disk scheduler is to handle file data requests A, B, and C to tracks (or
cylinders) 100, 50, and 190, respectively, and that the disk read/write head is initially at
track 140. Assume it takes 1 time-­‐unit for the disk to seek (move) a distance of one track. If
the file data requests are handled in first-­‐come-­‐first-­‐serve order (A,B,C), then the total seek
time is 40+50+140=230 time-­‐units. Suppose the requests S are to be serviced in the order
which minimizes total seek time instead. The goal is to compute the minimal seek time
f({A,B,C}, 140) = 190, which can be achieved by the order (C,A,B).
