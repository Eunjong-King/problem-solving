from line_profiler import LineProfiler

def test():
    # your code
    print("wow")

if __name__ == '__main__':
    line_profiler = LineProfiler()
    lp_wrapper = line_profiler(test)
    lp_wrapper()
    line_profiler.print_stats()