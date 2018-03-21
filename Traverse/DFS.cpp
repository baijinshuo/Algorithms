// Implement DFS for Tree
// Recursive method  
void DFS_Recursive(Node* pRoot)  
{  
    if (pRoot==NULL)  
        return;  
  
    cout<<pRoot->nVal<<" ";  
  
    if (pRoot->pLeft!=NULL)    
        DFS_Recursive(pRoot->pLeft);  
  
  
    if (pRoot->pRight!=NULL)  
        DFS_Recursive(pRoot->pRight);  
      
}  
  
// Iterative method(stack)  
void DFS_Iterative(Node* pRoot)  
{  
    if (pRoot==NULL)  
        return;  
  
    stack<Node*> S;  
    S.push(pRoot);  
  
    while (!S.empty())  
    {  
        Node *node=S.top();  
        cout<<node->nVal<<",";  
  
        S.pop();  
  
        if (node->pRight!=NULL)  
        {  
            S.push(node->pRight);  
        }  
  
        if (node->pLeft!=NULL)  
        {  
            S.push(node->pLeft);  
        }  
          
    }  
  
} 

// Implement DFS for graph
// Recursive method
void DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(v, visited);
}

// Iterative method
void DFS(int s)
{
    // Initially mark all verices as not visited
    vector<bool> visited(V, false);
 
    // Create a stack for DFS
    stack<int> stack;
 
    // Push the current source node.
    stack.push(s);
 
    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        s = stack.top();
        stack.pop();
 
        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited[s])
        {
            cout << s << " ";
            visited[s] = true;
        }
 
        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then puah it
        // to the stack.
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i])
                stack.push(*i);
    }
}