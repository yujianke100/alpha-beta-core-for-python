import numpy as np
import pyabcore
import pandas as pd
import os

root_path, _ = os.path.split(os.path.abspath(__file__)) 
df = pd.read_csv(root_path+'/data/graph.e', names=['u', 'i'], sep=' ', dtype=np.int32)
max_u = max(df['u'])+1
max_v = max(df['i'])+1
edges = np.array(df[['u','i']], dtype=np.int32)
test = pyabcore.Pyabcore(max_u, max_v)
test.index(edges)
test.query(2, 50)
print(np.array(test.get_left()))
print(np.array(test.get_right()))