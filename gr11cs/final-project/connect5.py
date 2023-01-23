""" Gomoku (Connect 5)

Two players, one blue player and one red player, alternate turns to place one stone of their color
on any empty spot on the board. The board contains 10 spots per side.
The blue player always goes first. The blue player has a choice of either playing against
another player (on the same device) or against an engine. The winner is the first player to
create an unbroken chain of 5 stones, vertically, horizontally, or diagonally.
"""

__author__ = "Andrew Peng"

import flet as ft
import random

# global variables for in-game variables
player1_name = "player 1"
player2_name = "player 2"
is_play_with_bot = False


# class to represent the game board
# UserControl allows the programmer to create an instance of the class
class Board(ft.UserControl):
    # specify that the global variable is to be used, not a new variable
    global is_play_with_bot
    global player1_name
    global player2_name
    # array to store which moves are valid
    available_spots = []
    is_player1 = True
    board = ft.Container
    is_game_over = False
    is_clear = False

    # self is implicitly passed, representing who called the function
    def create_grid(self, size: int) -> list[ft.Row]:
        """
        Returns a square 2D array representing the game board

        >>> create_grid(10)
        # creates a square 2D array
        """
        column = []
        row = []
        for i in range(size):
            # store each row of buttons in an array
            for j in range(size):
                row.append(
                    # ft.ElevatedButton is a clickable button
                    ft.ElevatedButton(
                        # attributes of the container
                        style=ft.ButtonStyle(shape=ft.CircleBorder()),
                        bgcolor=ft.colors.WHITE,
                        on_click=self.make_move,
                        # store the coordinates to use in other functions
                        data="({}, {})".format(i, j)
                    )
                )
                self.available_spots.append("({}, {})".format(i, j))
            # put the rows into the column array to create a 2D array board
            column.append(
                ft.Row(
                    controls=row
                )
            )
            row = []
        # ft.Row represents a vertical array (used for padding here)
        column.append(ft.Row(height=20))
        # ft.Container is a space where data can be added (will later be used to display messages)
        column.append(ft.Container())
        # return the 2D array representing the board (will later be put in an ft.Container)
        return column

    # there must be a constructor called build
    def build(self) -> ft.Container:
        """
        Returns a the board, a ft.Container object containing the 2D array from create_grid()

        >>> build()
        # returns an ft.Container
        """

        # self refers to member variables within this class (Board)
        self.board = ft.Container(
            alignment=ft.alignment.top_left,
            # content represents the data inside the container
            # puts the 2D array into an ft.Column object
            content=ft.Column(controls=self.create_grid(10)),
            width=770,
            height=530,
            bgcolor=ft.colors.BLUE,
            border_radius=ft.border_radius.all(20),
            padding=20
        )
        return self.board

    def update_adjacent_spots(self, adjacent_spots: list[str], row: int, column: int) -> list[str]:
        """
        If the coordinate (row, column) is empty, add it to adjacent_spots
        Returns adjacent_spots, a list of str containing the coordinates of adjacent spots

        # precondition: (row, column) is empty
        >>> update_adjacent_spots(adj, row, column)
        # adds the coordinate to adj and returns it
        """

        new_move = "({}, {})".format(row, column)
        if self.available_spots.count(new_move) > 0:
            adjacent_spots.append(new_move)
        return adjacent_spots

    def get_adjacent_spots(self, row: int, column: int) -> list[str]:
        """
        Returns list of str containing the coordinates of spots adjacent to the piece at (row, column)

        >>> update_adjacent_spots(adj, row, column)
        # returns adj, a list filled with the coordinates of the empty spots adjacent to (row, column)
        """

        adjacent_spots = []

        if row-1 >= 0:
            # if the spot above (row, column) is empty, add it to adjacent_spots
            self.update_adjacent_spots(adjacent_spots, row-1, column)

            # validate that the spot is inside the grid
            # this prevents an index error in the 2D array of the board
            if column-1 >= 0:
                self.update_adjacent_spots(adjacent_spots, row-1, column-1)

                self.update_adjacent_spots(adjacent_spots, row, column-1)

            # self is board object, controls is the array of elements stored in board,
            # controls[0] is an ft.Container, content is an ft.Column,
            # controls is an ft.Row containing the buttons
            # there are many layers because the datastructures are nested
            if column+1 < len(self.controls[0].content.controls):
                self.update_adjacent_spots(adjacent_spots, row-1, column+1)

                self.update_adjacent_spots(adjacent_spots, row, column+1)

        if row+1 < len(self.available_spots):
            self.update_adjacent_spots(adjacent_spots, row+1, column)

            if column-1 >= 0:
                self.update_adjacent_spots(adjacent_spots, row+1, column-1)

            if column+1 < len(self.controls[0].content.controls):
                self.update_adjacent_spots(adjacent_spots, row+1, column+1)

        return adjacent_spots

    # both self and e are implicitly passed
    # e is the event that triggers this action (in this case, a button click)
    def make_move(self, e: ft.Event):
        """
        Store the current move and place it on the board with the update_board_move method
        If it is the robot's turn, pick a move for the robot

        # calling this function has no parentheses because the parameters are implicit
        precondition: on user's turn, user clicked on an empty spot (button) on the board
        >>> make_move
        # the spot is now colored with the user's color
        """

        if self.is_game_over == True:
            return

        move = e.control.data
        row = int(move[1])
        column = int(move[4])

        # places the move on the board and checks the status of the game (e.g., if someone won)
        self.update_board_move(move, row, column)

        # it is the robot's turn
        if is_play_with_bot and not self.is_player1:
            new_move = ""
            adjacent_spots = self.get_adjacent_spots(row, column)

            # if there are emtpy adjacent spots to the player's most recent move,
            # pick a random spot among those adjacent spots
            if len(adjacent_spots) > 0:
                move = adjacent_spots[random.randint(
                    0, len(adjacent_spots)-1)]
            # if there are no adjacent spots, pick a random spot on the board
            else:
                move = self.available_spots[random.randint(
                    0, len(self.available_spots)-1)]
            # move is stored in a string
            row = int(move[1])
            column = int(move[4])
            self.update_board_move(move, row, column)

    def update_board_move(self, move: str, row: int, column: int):
        """
        Places the current move on the board and checks the status of the game
        (if a player won, an illegal move was made, or the board is full)

        precondition: the user placed the 5th piece in a continuous row of 4 pieces
        >>> update_board_move
        # the spot is now colored with the user's color
        # the board outputs a message stating that the user won
        """

        # the current move is in the array of available moves
        if self.available_spots.count(move) > 0:
            if self.is_player1:
                # color the button yellow
                self.controls[0].content.controls[row].controls[column].bgcolor = ft.colors.YELLOW
            else:
                self.controls[0].content.controls[row].controls[column].bgcolor = ft.colors.RED
            self.available_spots.remove(move)

            # user has an unbroken chain of exactly 5 pieces (user won)
            if self.is_won(row, column):
                self.is_game_over = True
                if self.is_player1:
                    player = player1_name
                else:
                    player = player2_name
                self.controls[0].content.controls[11] = ft.Container(
                    border_radius=ft.border_radius.all(20),
                    padding=20,
                    bgcolor=ft.colors.BLACK,
                    width=800,
                    content=ft.Row(
                        alignment=ft.MainAxisAlignment.CENTER,
                        scroll=ft.ScrollMode.ALWAYS,
                        controls=[
                            ft.Text(
                                "GAME OVER! {} WON!".format(player),
                                style=ft.TextThemeStyle.DISPLAY_SMALL,
                                color=ft.colors.WHITE,
                                text_align=ft.TextAlign.CENTER
                            )
                        ]
                    )
                )

            # there are no more available spots (game is over)
            elif len(self.available_spots) == 0:
                self.controls[0].content.controls[11] = ft.Container(
                    border_radius=ft.border_radius.all(20),
                    padding=20,
                    bgcolor=ft.colors.BLACK,
                    width=800,
                    content=ft.Row(
                        alignment=ft.MainAxisAlignment.CENTER,
                        scroll=ft.ScrollMode.ALWAYS,
                        controls=[
                            ft.Text(
                                "GAME OVER!. TIED GAME!. BOARD IS FULL!",
                                style=ft.TextThemeStyle.DISPLAY_SMALL,
                                color=ft.colors.WHITE,
                                text_align=ft.TextAlign.CENTER
                            )
                        ]
                    )
                )
                self.is_game_over = True

            # a valid move is made
            else:
                if self.is_clear:
                    self.controls[0].content.controls[11] = ft.Container()
                self.is_player1 = not self.is_player1
                self.is_clear = False

        # an invalid move is made
        else:
            self.is_clear = True
            self.controls[0].content.controls[11] = ft.Container(
                border_radius=ft.border_radius.all(20),
                padding=20,
                bgcolor=ft.colors.BLACK,
                width=800,
                content=ft.Row(
                    alignment=ft.MainAxisAlignment.CENTER,
                    scroll=ft.ScrollMode.ALWAYS,
                    controls=[
                        ft.Text(
                            "THAT SPOT IS TAKEN! TRY ANOTHER SPOT!",
                            style=ft.TextThemeStyle.DISPLAY_SMALL,
                            color=ft.colors.WHITE,
                            text_align=ft.TextAlign.CENTER
                        )
                    ])
            )
        # updates the page containing the board (shows the message/newly colored spot)
        self.update()

    def is_won(self, row: int, column: int) -> bool:
        """
        Returns true if a player has an unbroken chain of 5 pieces, false otherwise
        Checks if the user won by checking if the most recent move is part of chain of 5 pieces

        precondition: the longest chain adjacent to (row, column) has length 2
        >>> is_won(1, 1)
        # returns false
        """

        num_in_row = 1
        # color of the player that placed the most recent move
        current_color = self.board.content.controls[row].controls[column].bgcolor
        # determines whether or not to check a direction
        # dir1 and dir2 are opposite directions (e.g., left and right)
        enter_dir1 = True
        enter_dir2 = True
        # the length of a row (which is also the length of a column, since the board is square)
        grid_side_length = len(self.board.content.controls[00].controls)

        # check horizontal (left and right)
        for i in range(1, 6):
            # the index is out of range
            if column-i < 0:
                # stop checking in this direction
                enter_dir1 = False
            if column+i >= grid_side_length:
                enter_dir2 = False

            # there is an adjacent piece of the same color in this direction
            if enter_dir1 and current_color == self.board.content.controls[row].controls[column-i].bgcolor:
                num_in_row += 1
            else:
                enter_dir1 = False
            if enter_dir2 and current_color == self.board.content.controls[row].controls[column+i].bgcolor:
                num_in_row += 1
            else:
                enter_dir2 = False
        # the player wins if there is a chain of exactly 5 pieces
        if num_in_row == 5:
            # no need to check other directions
            return True

        # check vertical (up and down)
        num_in_row = 1
        enter_dir1 = True
        enter_dir2 = True
        for i in range(1, 6):
            if row-i < 0:
                enter_dir1 = False
            if row+i >= grid_side_length:
                enter_dir2 = False

            if enter_dir1 and current_color == self.board.content.controls[row-i].controls[column].bgcolor:
                num_in_row += 1
            else:
                enter_dir1 = False
            if enter_dir2 and current_color == self.board.content.controls[row+i].controls[column].bgcolor:
                num_in_row += 1
            else:
                enter_dir2 = False
        if num_in_row == 5:
            return True

        # check major diagonal (top left to bottom right)
        num_in_row = 1
        enter_dir1 = True
        enter_dir2 = True
        for i in range(1, 6):
            if row-i < 0 or column-i < 0:
                enter_dir1 = False
            if row+i >= grid_side_length or column+i >= grid_side_length:
                enter_dir2 = False

            if enter_dir1 and current_color == self.board.content.controls[row-i].controls[column-i].bgcolor:
                num_in_row += 1
            else:
                enter_dir1 = False
            if enter_dir2 and current_color == self.board.content.controls[row+i].controls[column+i].bgcolor:
                num_in_row += 1
            else:
                enter_dir2 = False
        if num_in_row == 5:
            return True

        # check minor diagonal (bottom left to top right)
        num_in_row = 1
        enter_dir1 = True
        enter_dir2 = True
        for i in range(1, 6):
            if row+i >= grid_side_length or column-i < 0:
                enter_dir1 = False
            if row-i < 0 or column+i >= grid_side_length:
                enter_dir2 = False

            if enter_dir1 and current_color == self.board.content.controls[row+i].controls[column-i].bgcolor:
                num_in_row += 1
            else:
                enter_dir1 = False
            if enter_dir2 and current_color == self.board.content.controls[row-i].controls[column+i].bgcolor:
                num_in_row += 1
            else:
                enter_dir2 = False

        # since this is the last direction, return false if there is no chain of 5 pieces
        return num_in_row == 5


def set_player_name(e):
    """
    Sets the values of the global player name variables

    precondition: data was just entered into the ft.TextField for player 1's name
    >>> set_player_name
    # player1_name now has the value specified by the user
    """

    global player1_name, player2_name
    if e.control.data == "p1":
        player1_name = e.control.value
    else:
        player2_name = e.control.value


def clear_board(e):
    """
    Reset the board and the available_spots array to their intial empty values

    >>> clear_board
    # the board object's buttons revert back to their initial colors and available_spots is empty
    """

    Board.available_spots = []
    e.page.views[0].controls[0].controls[0] = Board()
    e.page.update()


def create_2player_interface(e):
    """
    Create the appropriate ft.TextField and button for 2-player mode
    Append the newly created strutures to the board

    >>> create_2player_interface
    # a new ft.TextField and button are displayed
    """

    # get rid of the "play with another person" and "play solo" buttons
    e.control.page.views[1].controls[0].controls.pop()
    e.control.page.views[1].controls[0].controls.pop()

    # append a container with the new data
    e.control.page.views[1].controls[0].controls.append(
        ft.Container(
            width=850,
            content=ft.TextField(
                label="Player 2, enter your name (default name is \"player 2\"):",
                # tag this ft.TextField as p2 (player 2) to differentiate between the ft.TextField for p1
                data="p2",
                on_change=set_player_name
            )
        ),
    )

    e.control.page.views[1].controls[0].controls.append(
        ft.ElevatedButton(
            "Play!",
            # go to the game page
            # this program has 2 pages: the welcome page and the game page
            on_click=lambda _: e.control.page.go("/game")
        )
    )
    e.page.update()


def create_welcome_view(page: ft.page) -> list[ft.Column]:
    """
    Create the title, instructions, default ft.TextField and default buttons
    Append the newly created strutures to the board

    >>> create_welcome_view
    # title, instructions, buttons, and a ft.TextField are displayed
    """

    # this array will be used as the data for the page in the route_change function
    return [
        ft.Column(
            scroll=ft.ScrollMode.ALWAYS,
            controls=[
                # store ft.Column in an ft.Container to allow background color
                ft.Container
                (
                    bgcolor=ft.colors.BLUE,
                    border_radius=ft.border_radius.all(
                        20),
                    padding=20,
                    # Game title
                    content=ft.Column(
                        controls=[
                            ft.Text(
                                "Gomoku (Connect 5)\nBy: Andrew Peng",
                                size=50,
                                weight=ft.FontWeight.BOLD
                            ),

                            ft.Text(
                                "Welcome",
                                size=50
                            )
                        ]
                    )
                ),
                ft.Container(
                    bgcolor=ft.colors.BLUE_100,
                    border_radius=ft.border_radius.all(20),
                    padding=20,
                    # Game instructions
                    content=ft.Text
                    (
                        "Create an unbroken chain of exactly 5 stones, vertically, horizontally, or diagonally, to win.\nPlace stones onto any empty space on the board.",
                        size=20,
                    )
                ),
                ft.Container(
                    width=850,
                    content=ft.TextField(
                        label="Player 1, enter your name (default name is \"player 1\"):",
                        data="p1",
                        on_change=set_player_name
                    )
                ),

                ft.ElevatedButton(
                    "Play with another person",
                    on_click=create_2player_interface
                ),
                ft.ElevatedButton(
                    "Play solo!",
                    on_click=play_with_bot
                ),
            ]
        )
    ]


def play_with_bot(e):
    """
    Sets variables to the appropriate state for playing with bot

    >>> play_with_bot
    # player2_name is set to "gomuku bot", is_play_with_bot is true
    # goes to game page
    """

    global player2_name
    player2_name = "gomuku bot"
    global is_play_with_bot
    is_play_with_bot = True
    e.page.go("/game")


def clear_all_variables_except_bot():
    """
    Clears all variables except is_play_with_bot
    This function is used when the player clicks the "return to main menu" button on the game page

    >>> clear_all_variables_except_bot
    # all variables except is_play_with_bot are cleared
    """

    global player1_name
    player1_name = "player 1"
    global player2_name
    player2_name = "player 2"
    Board.available_spots = []
    Board.is_player1 = True
    Board.board = ft.Container
    Board.is_game_over = False
    Board.is_clear = False


def reset_and_return_to_menu(e):
    """
    Clears all variables and goes to welcome page
    This function is used when the player clicks the "return to main menu" button on the game page

    >>> reset_and_return_to_menu
    # all variables are cleared
    # goes to welcome menu page
    """

    clear_all_variables_except_bot()
    global is_play_with_bot
    is_play_with_bot = False
    e.page.go("/")


def create_game_view(page: ft.page, player1_name: str, player2_name: str) -> list[ft.Row]:
    """
    Returns an array containing the data (main container is ft.Row) for the game page

    >>> create_game_view
    # data for the page is created
    """

    return [
        ft.Row(
            scroll=ft.ScrollMode.ALWAYS,
            vertical_alignment=ft.CrossAxisAlignment.START,
            alignment=ft.MainAxisAlignment.CENTER,
            controls=[
                Board(),
                ft.Container(
                    width=50
                ),
                ft.Container(
                    alignment=ft.alignment.top_left,
                    content=ft.Column(
                        scroll=ft.ScrollMode.ALWAYS,
                        controls=[
                            ft.Container(
                                alignment=ft.alignment.top_left,
                                width=300,
                                bgcolor=ft.colors.YELLOW,
                                border_radius=ft.border_radius.all(
                                    20),
                                padding=20,
                                content=ft.Text(player1_name)
                            ),
                            ft.Container(
                                alignment=ft.alignment.top_left,
                                width=300,
                                bgcolor=ft.colors.RED,
                                border_radius=ft.border_radius.all(
                                    20),
                                padding=20,
                                content=ft.Text(player2_name)
                            ),
                            ft.Container(
                                width=300,
                                height=250
                            ),
                            ft.Container(
                                alignment=ft.alignment.top_left,
                                width=300,
                                bgcolor=ft.colors.BLUE,
                                border_radius=ft.border_radius.all(
                                    20),
                                padding=20,
                                content=ft.Column(
                                    scroll=ft.ScrollMode.ALWAYS,
                                    controls=[
                                        ft.ElevatedButton(
                                            "Play Again",
                                            on_click=clear_board
                                        ),
                                        ft.ElevatedButton(
                                            "Back to Main Menu",
                                            on_click=reset_and_return_to_menu
                                        )
                                    ]
                                )
                            )
                        ]
                    )
                )
            ]
        )
    ]


def main(page: ft.page):
    """
    The driver function for the game
    """

    page.title = "Connect 5"
    page.scroll = ft.ScrollMode.ALWAYS

    def route_change(route):
        """
        Changes the current page
        Implicitly called
        """
        page.scroll = ft.ScrollMode.ALWAYS
        page.views.append(
            ft.View(
                "/",
                create_welcome_view(page),
            )
        )

        if page.route == "/game":
            page.scroll = ft.ScrollMode.ALWAYS
            # get rid of the other views
            # allows buttons on the welcome menu to function after pressing the "main menu" button
            page.views.clear()
            page.views.append(
                ft.View(
                    "/game",
                    create_game_view(page, player1_name,
                                     player2_name)
                )
            )

        page.update()

    def view_pop(view):
        """
        Upon entering a new view, pop the previous views from the stack
        Implicitly called
        """
        page.views.pop()
        top_view = page.views[-1]
        page.go(top_view.route)

    page.on_view_pop = view_pop
    page.on_route_change = route_change
    page.go(page.route)


# the entry point of the app session is the main function
ft.app(target=main)
