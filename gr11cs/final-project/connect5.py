import flet as ft


class Board(ft.UserControl):
    unavailable_spots = []
    is_player1 = True
    board = ft.Container

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
            content=ft.Column(controls=self.create_grid(10)),
            width=770,
            height=520,
            bgcolor=ft.colors.BLUE,
            border_radius=10,
            padding=10
        )
        return self.board

    def make_move(self, e):
        row = int(e.control.data[1])
        column = int(e.control.data[4])
        print(row, column)
        while self.unavailable_spots.count(e.control.data) != 0:
            print("That spot is taken. Try again.")
        if self.is_player1:
            e.control.bgcolor = ft.colors.YELLOW
        else:
            e.control.bgcolor = ft.colors.RED

        if self.is_won(row, column):
            print("won")
            if self.is_player1:
                player = "player 1"
            else:
                player = "player 2"
            self.page.views.append(
                ft.View(
                    ft.Text(
                        player+"won!"
                    )
                )
            )
        elif len(self.unavailable_spots.count) == len(self.board.content.controls)**2:
            print("board full")
        else:
            self.unavailable_spots.append(e.control.data)
            self.is_player1 = not self.is_player1
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


def main(page: ft.page):
    page.title = "Connect 5"

    def route_change(route):
        page.views.append(
            ft.View(
                "/",
                [
                    ft.Text(
                        "Gomoku (Connect 5)",
                        bgcolor=ft.colors.AMBER_100,
                        size=50,
                        weight=ft.FontWeight.BOLD
                    ),
                    ft.ElevatedButton(
                        "Continue",
                        on_click=lambda _: page.go("/welcome")
                    )
                ]
            )
        )
        if page.route == "/welcome":
            page.views.append(
                ft.View(
                    "/welcome",
                    [
                        ft.Text(
                            "Welcome",
                            bgcolor=ft.colors.AMBER_100,
                            size=50
                        ),
                        ft.TextField(label="Player 1, enter your name:"),
                        ft.ElevatedButton(
                            "Continue",
                            on_click=lambda _: page.go("/mainmenu")
                        )
                    ]
                )
            )
        if page.route == "/mainmenu":
            page.views.append(
                ft.View(
                    "/mainmenu",
                    [
                        ft.Text(
                            "Main Menu",
                            bgcolor=ft.colors.AMBER_100,
                            size=50
                        ),
                        ft.ElevatedButton(
                            "Play with another human", on_click=lambda _: page.go("/humanmenu")),
                        ft.ElevatedButton(
                            "Play with engine",
                            on_click=lambda _: page.go("/board")
                        ),
                    ]
                )
            )
        if page.route == "/humanmenu":
            page.views.append(
                ft.View(
                    "/humanmenu",
                    [
                        ft.Text(
                            "Human Menu",
                            bgcolor=ft.colors.AMBER_100,
                            size=50
                        ),
                        ft.TextField(label="Player 2, enter your name:"),
                        ft.ElevatedButton(
                            "Play!",
                            on_click=lambda _: page.go("/board")
                        )
                    ]
                )
            )
        if page.route == "/board":
            page.views.append(
                ft.View(
                    "/board",
                    [
                        Board(),
                        ft.ElevatedButton(
                            "Back to Main Menu",
                            on_click=lambda _: page.go("/")
                        ),
                    ]
                )
            )

        page.update()

    page.on_route_change = route_change
    page.go(page.route)


ft.app(target=main)
