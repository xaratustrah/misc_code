#!/usr/bin/env python
#
# from multiprocessing import Process, Queue
# import time
#
#
# class FancyClass():
#     def __init__(self, q):
#         self.q = q
#
#     @staticmethod
#     def f(q):
#         while True:
#             q.put([42, None, 'hello'])
#             time.sleep(0.05)
#
#
# if __name__ == '__main__':
#     q = Queue()
#     fc = FancyClass(q)
#     p = Process(target=fc.f, args=(q,))
#     p.start()
#     try:
#         while True:
#             print(q.get())  # prints "[42, None, 'hello']"
#
#     except(EOFError, KeyboardInterrupt):
#         p.terminate()
#         print('\nThe End!')



from multiprocessing import Process, Queue
import time


class Processor(Process):
    def __init__(self, q):
        super(Processor, self).__init__()
        #Process.__init__(self)
        self.q = q

    def run(self):
        while True:
            self.q.put('Hello')
            time.sleep(0.05)


if __name__ == '__main__':
    q = Queue()
    p = Processor(q)
    p.start()
    #    p.join()
    try:
        while True:
            print(q.get())  # prints "[42, None, 'hello']"

    except(EOFError, KeyboardInterrupt):
        print('\nUser input cancelled. Aborting...')
        p.terminate()
