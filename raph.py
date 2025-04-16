import matplotlib.pyplot as plt
import networkx as nx

# Create a directed graph
G = nx.DiGraph()

# Add edges with weights
edges = [
    (1, 2, 2),
    (1, 3, 1),
    (2, 4, 2),
    (2, 5, 3),
    (3, 5, 9),
    (4, 6, 6),
    (5, 6, 7),
    (6, 7, 4)
]

# Add edges to the graph
G.add_weighted_edges_from(edges)

# Draw the graph
pos = nx.spring_layout(G)  # or nx.circular_layout(G) for different layout
nx.draw(G, pos, with_labels=True, node_size=2000, node_color="skyblue", font_size=10, font_weight="bold", arrows=True)

# Add edge labels (weights)
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

# Show the plot
plt.title("Graph Visualization")
plt.show()
