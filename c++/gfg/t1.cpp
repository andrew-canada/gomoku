class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        vector<int> snake;
        for(int i = 0; i<matrix.size(); i++){
            if(i%2==0){
                for(int j = 0; j<matrix[i].size(); j++){
                    snake.push_back(matrix[i][j]);
                }
            }else{
                for(int j = matrix[i].size()-1; j>=0; j--){
                    snake.push_back(matrix[i][j]);
                }
            }
        }
        return snake;
    }
};