# from google.colab import output

def render(grid):
  # draw grid
  for i in range(5):
    for j in range(3):
      if i % 2 != 0:
        if j == 0 or j == 1:
          print("-", end="")
        else:
          print("-")
      else:
        if j == 0 or j == 1:
          print(grid[i][j] + " | ", end="")
        else:
          print(grid[i][j])


def make_move(grid, row, col, symbol):
  # draws an x or o in the given row and column
  pass

def winner(grid):
  # calculates if a player has won
  pass

def main():
  grid = [[" ", " ", " "], [" ", " ", " "], [" ", " ", " "]]
  render(grid)
  """
  while(!winner(grid))
  render(initial_grid)
  """

for i in range(10):
  print("a")
  # output.clear()

main()

