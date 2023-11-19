# greedy

## general structure

```c++
getOptimal(Item arr[], int n){
    initialize ans;
    while(not all items are selected){
        i = selectAnItem();
        if(feasible(i)){
            ans+=i;
        }
    }
    return ans;
}
```
