package cs420_p3;

import java.util.ArrayList;

public class Node {
	private State state;
	private Node parentNode;
	private int pathCost;
	private int depth;
	private int heuristic;
	
	public Node() {
		// Empty node to initialize Priority Queue
	}
	
	/**
	 * Initialize a node.
	 * @param state - The current configuration of the 8-puzzle.
	 * @param parentNode - Parent Node.
	 * @param depth - Current Depth
	 * @param heuristics - Current Heuristics of that state
	 */
	public Node(State state, Node parentNode, int depth, int heuristic) {
		this.state = state;
		pathCost = 1;	
		this.depth = depth;
		this.parentNode = parentNode;
		this.heuristic = heuristic;
	}
	
	public void printSolutionPath() {
		ArrayList<State> tempStateStorage = new ArrayList<State>();
		tempStateStorage.add(this.getState());
		Node parentNode = this.getParentNode();
		
		do {
			tempStateStorage.add(parentNode.getState());
			parentNode = parentNode.getParentNode();
		} while (parentNode != null);
		
		for (int i = tempStateStorage.size() - 1; i >= 0; i--) {
			tempStateStorage.get(i).printState();
		}
	}
		
	
	// Getters and setters
	public int getHeuristic() {
		return heuristic;
	}
	
	public State getState() {
		return state;
	}

	public Node getParentNode() {
		return parentNode;
	}

	public int getPathCost() {
		return pathCost;
	}

	public int getDepth() {
		return depth;
	}

}