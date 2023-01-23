import flet as ft

player1_name = "player 1"
player2_name = "player 2"
is_play_with_bot = False

class Board(ft.UserControl):
    global is_play_with_bot
    available_spots = []
    is_player1 = True
    board = ft.Container
    is_game_over = False
    is_clear = False

    def create_grid(self, size: int):
        column = []
        row = []
        for i in range(size):
            for j in range(size):
                row.append(
                    ft.ElevatedButton(
                        style=ft.ButtonStyle(shape=ft.CircleBorder()),
                        bgcolor=ft.colors.WHITE,
                        on_click=self.make_move,
                        data="({}, {})".format(i, j)
                    )
                )
                self.available_spots.append("({}, {})".format(i, j))
            column.append(
                ft.Row(
                    controls=row
                )
            )
            # using clear() will enpty everything because same reference
            row = []
        return column

    # must be called build
    # Exception: Board.build() method must be implemented and returning either Control or List[Control].
    def build(self):
        self.board = ft.Container(
            alignment=ft.alignment.top_left,
            content=ft.Column(controls=self.create_grid(10)),
            width=770,
            height=530,
            bgcolor=ft.colors.BLUE,
            border_radius=ft.border_radius.all(20),
            padding=20
        )
        return self.board

    def make_move(self, e):
        print(is_play_with_bot)
        if self.is_game_over == True:
            return
        row = int(e.control.data[1])
        column = int(e.control.data[4])
        print(row, column)
        if self.available_spots.count(e.control.data) != 0:
            if self.is_player1:
                e.control.bgcolor = ft.colors.YELLOW
            else:
                e.control.bgcolor = ft.colors.RED

            if self.is_won(row, column):
                self.is_game_over = True
                print("won")
                if self.is_player1:
                    player = player1_name
                else:
                    player = player2_name
                self.controls[0].content.controls.insert(
                    10,
                    ft.Row(
                        controls=[
                            ft.Text("GAME OVER! {} WON!".format(player),
                                    style=ft.TextThemeStyle.DISPLAY_LARGE)
                        ])
                )
            elif len(self.available_spots) == 0:
                self.controls[0].content.controls.insert(
                    10,
                    ft.Row(
                        controls=[
                            ft.Text("GAME OVER!. TIED GAME!. BOARD IS FULL!",
                                    style=ft.TextThemeStyle.DISPLAY_LARGE)
                        ])
                )
                self.is_game_over = True
            else:
                if self.is_clear:
                    self.controls[0].content.controls.pop(-1)
                self.available_spots.remove(e.control.data)
                self.is_player1 = not self.is_player1
                self.is_clear = False

        else:
            self.is_clear = True
            self.controls[0].content.controls.insert(
                10,
                ft.Row(
                    controls=[
                        ft.Text("THAT SPOT IS TAKEN! TRY ANOTHER SPOT!",
                                style=ft.TextThemeStyle.DISPLAY_LARGE)
                    ])
            )

        self.update()

    def is_won(self, row, column):
        num_in_row = 1
        current_color = self.board.content.controls[row].controls[column].bgcolor
        enter_dir1 = True
        enter_dir2 = True
        grid_side_length = len(self.board.content.controls)
        # left or right
        for i in range(1, 6):
            if column-i < 0:
                enter_dir1 = False
            if column+i >= grid_side_length:
                enter_dir2 = False

            if enter_dir1 and current_color == self.board.content.controls[row].controls[column-i].bgcolor:
                num_in_row += 1
            else:
                enter_dir1 = False
            if enter_dir2 and current_color == self.board.content.controls[row].controls[column+i].bgcolor:
                num_in_row += 1
            else:
                enter_dir2 = False
        if num_in_row == 5:
            return True

        # up or down
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

        # major diagonal (top left to bottom right)
        num_in_row = 1
        enter_dir1 = True
        enter_dir2 = True
        for i in range(1, 6):
            if row+i < 0 or column-i < 0:
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

        # minor diagonal (bottom left to top right)
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

        return num_in_row == 5


def set_player_name(e):
    print("aaa")
    global player1_name, player2_name
    if e.control.data == "p1":
        player1_name = e.control.value
    else:
        player2_name = e.control.value


def clear_board(e):
    print("a")
    print(e.page.views[0].controls[0].controls[0])

    b = Board()
    print(b)

    e.page.views[0].controls[0].controls[0]=b
    e.page.update()
    print(e.data)


def create_2player_interface(e):
    e.control.page.views[1].controls[0].controls.pop()
    e.control.page.views[1].controls[0].controls.pop()
    e.control.page.views[1].controls[0].controls.append(
        ft.TextField(
            label="Player 2, enter your name (default name is \"player 2\"):",
            data="p2",
            on_change=set_player_name
        ),
    )

    e.control.page.views[1].controls[0].controls.append(
        ft.ElevatedButton(
            "Play!",
            on_click=lambda _: e.control.page.go("/game")
        )
    )
    e.page.update()


def create_welcome_view(page: ft.page):
    return [
        ft.Column(
            controls=[
                ft.Text(
                    "Gomoku (Connect 5)",
                    bgcolor=ft.colors.AMBER_100,
                    size=50,
                    weight=ft.FontWeight.BOLD
                ),

                ft.Text(
                    "Welcome",
                    bgcolor=ft.colors.AMBER_100,
                    size=50
                ),
                ft.TextField(
                    label="Player 1, enter your name (default name is \"player 1\"):",
                    data="p1",
                    on_change=set_player_name
                ),

                ft.ElevatedButton(
                    "Play with another person",
                    on_click=create_2player_interface
                ),
                ft.ElevatedButton(
                    "Play solo!",
                    # on_click=lambda _: page.go("/game")
                    on_click=play_with_bot
                ),
            ]
        )
    ]


def play_with_bot(e):
    global is_play_with_bot
    is_play_with_bot = True
    e.page.go("/game")


def create_game_view(page: ft.page, player1_name: str, player2_name: str):
    return [
        ft.Row(
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
                                    controls=[
                                        ft.ElevatedButton(
                                            "Play Again",
                                            on_click=clear_board
                                        ),
                                        ft.ElevatedButton(
                                            "Back to Main Menu",
                                            on_click=lambda _: page.go("/")
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

    page.title = "Connect 5"

    def route_change(route):
        page.views.append(
            ft.View(
                "/",
                create_welcome_view(page)
            )
        )

        if page.route == "/game":
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
        page.views.pop()
        top_view = page.views[-1]
        page.go(top_view.route)

    page.on_view_pop = view_pop
    page.on_route_change = route_change
    page.go(page.route)


ft.app(target=main)
