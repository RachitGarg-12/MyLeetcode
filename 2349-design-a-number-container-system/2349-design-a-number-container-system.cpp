class NumberContainers {
public:
   map<int,set<int>> umap;
    map<int,int> ind;
    NumberContainers() {
        umap.clear();
        ind.clear();
    }
    
    void change(int index, int number) {
        if(ind.find(index)!=ind.end())
        {
            umap[ind[index]].erase(index);
            ind[index] = number;
        }
        else
           ind[index] = number;
          umap[number].insert(index); 
    }
    
    int find(int number) {
        if(umap.find(number)==umap.end() || umap[number].size()==0)
            return -1;
        return *umap[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */