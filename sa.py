import numpy as np
import pandas as pd
import pyopencl as cl
import os

# Display C++ compiler output
os.environ['PYOPENCL_COMPILER_OUTPUT'] = '1'

# Always choose the GPU, comment this line to manually choose
os.environ['PYOPENCL_CTX'] = '0:2'

ctx = cl.create_some_context()
queue = cl.CommandQueue(ctx)
mf = cl.mem_flags

# Read the data files
path = '../Datagenerator/'
filename = 'data_0.txt'
f = open(path + filename)
n = int(f.readline())
m = int(f.readline())
print n
print m
df = pd.read_csv('../DataGenerator/data_0.txt', skiprows=2, header=None, skip_blank_lines=True, nrows=n, delim_whitespace=True)
print df

a_np = np.random.rand(50000).astype(np.float32)

prg = cl.Program(ctx, """
__kernel void sum(__global float *res_g) {
  int gid = get_global_id(0);
  res_g[gid] = gid;
}
""").build()

res_g = cl.Buffer(ctx, mf.WRITE_ONLY, a_np.nbytes)
prg.sum(queue, a_np.shape, None, res_g)

res_np = np.empty_like(a_np)
cl.enqueue_copy(queue, res_np, res_g)

print res_np
