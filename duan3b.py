import matplotlib.pyplot as plt
import numpy as np
import networkx as nx

weight_matrix = np.array([[0, 73, 98, 9, 33],
                          [16, 0, 98, 58, 61],
                          [84, 49, 0, 13, 63],
                          [4, 50, 56, 0 ,98],
                          [99, 1, 90, 58, 0]])

G = nx.from_numpy_array(weight_matrix)

pos = nx.spring_layout(G)
nx.draw(G, with_labels=True, node_color='lightblue', node_size=800, font_size=12, font_weight='bold')

labels = nx.get_edge_attributes(G, 'weight')
for edge, weight in labels.items():
    x, y = pos[edge[0]], pos[edge[1]]
    plt.text((x[0] + y[0]) / 2, (x[1] + y[1]) / 2, weight, ha='center', va='center')


plt.show()