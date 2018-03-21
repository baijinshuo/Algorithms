// Implement BFS for tree
void BFS(Node *pRoot)  
{  
    if (pRoot==NULL)  
        return;  
  
    queue<Node*> Q;  
  
    Q.push(pRoot);  
  
    while(!Q.empty())  
    {  
          
        Node *node = Q.front();  
  
        cout<<node->nVal<<"->";  
        if (node->pLeft!=NULL)  
        {  
            Q.push(node->pLeft);  
        }  
  
        if (node->pRight!=NULL)  
        {  
            Q.push(node->pRight);  
        }  
  
        Q.pop();  
    }  
  
    cout<<endl;  
}  

// Implement BFS for graph
void BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited, 
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
