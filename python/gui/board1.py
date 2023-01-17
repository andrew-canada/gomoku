import time
import os
import random

import flet
from flet import (
    Column,
    Container,
    GridView,
    Icon,
    IconButton,
    Page,
    Row,
    SnackBar,
    Text,
    TextButton,
    TextField,
    UserControl,
    alignment,
    colors,
    icons,
    ElevatedButton,
    border,
    border_radius,
    ButtonStyle,
    CircleBorder,
    CrossAxisAlignment,
    MainAxisAlignment,
    ScrollMode,
    View,
    AppBar,
)

# logging.basicConfig(level=logging.INFO)

os.environ["FLET_WS_MAX_MESSAGE_SIZE"] = "8000000"
play1_name = "no name"

def play_again(e):
    print("play again")


def exit(e):
    print("exit")


class GameBoard(UserControl):
    x = 1
    play_with_bot = True
    not_occupied_cells = ["1|1", "2|2", "3|2", "6|4", "5|5"]

    def __init__(self, expand=False, height=500):
        super().__init__()

        if expand:
            self.expand = expand
        else:
            self.height = height

    def build(self):

        return Container(
            width=770,
            height=530,
            bgcolor=colors.BLUE,
            border_radius=border_radius.all(20),
            padding=20,
            content=Column(
                controls=self.create_row(10)
            )
        )

    def create_row(self, size):
        column = []
        row_item = []
        for i in range(1, size + 1):
            for j in range(1, size + 1):
                row_item.append(
                    ElevatedButton(
                        text="",
                        bgcolor=colors.BLUE_GREY_100,
                        style=ButtonStyle(shape=CircleBorder()),
                        on_click=self.test_click,
                        data="{}|{}".format(i, j),
                    )
                )
            column.append(
                Row(
                    controls=row_item
                )
            )
            row_item = []
        return column

    def test_click(self, e):
        icon_key = e.control.data
        if self.x == 1:
            e.control.bgcolor = colors.BLACK
            self.x = 0
        else:
            e.control.bgcolor = colors.RED
            self.x = 1
        self.update()

        random_index = random.randint(1, len(self.not_occupied_cells))
        bot_move = self.not_occupied_cells.pop(random_index).split('|')
        r = int(bot_move[0])
        c = int(bot_move[1])
        if self.play_with_bot:
            time.sleep(0.5)
            self.controls[0].content.controls[r].controls[c].bgcolor = colors.RED
            self.x = 1
            self.update()
        print("Copy to clipboard:", icon_key)


def main(page: Page):
    page.title = "Chinese Connect 5"

    def textbox_changed(e):
        global play1_name
        play1_name = e.control.value

    def route_change(route):

        page.views.append(
            View(
                "/",
                [
                    Text("welcome to 连五子"),
                    TextField(
                        label="Textbox with 'change' event:",
                        on_change=textbox_changed,
                    ),
                    ElevatedButton(
                        "play", on_click=lambda _: page.go("/board")),
                ],
            )
        )

        if page.route == "/board":
            page.views.append(
                View(
                    "/board",
                    [
                        Row(
                            vertical_alignment=CrossAxisAlignment.START,
                            alignment=MainAxisAlignment.CENTER,
                            controls=[
                                GameBoard(expand=True),
                                Container(
                                    alignment=alignment.top_left,
                                    width=300,
                                    bgcolor=colors.WHITE,
                                    border_radius=border_radius.all(20),
                                    padding=20,
                                    content=Column(
                                        controls=[
                                            Container(
                                                alignment=alignment.top_left,
                                                width=300,
                                                bgcolor=colors.RED,
                                                border_radius=border_radius.all(
                                                    20),
                                                padding=20,
                                                content=Column(
                                                    controls=[
                                                        Text(play1_name),
                                                    ]
                                                )
                                            ),
                                            Container(
                                                width=300,
                                                bgcolor=colors.GREEN,
                                                border_radius=border_radius.all(
                                                    20),
                                                padding=20,
                                                content=Column(
                                                    controls=[
                                                        Text("Player2"),
                                                    ]
                                                )
                                            ),
                                            Container(
                                                alignment=alignment.bottom_center,
                                                width=300,
                                                height=200,
                                                bgcolor=colors.WHITE,
                                                border_radius=border_radius.all(
                                                    20),
                                                padding=20,
                                            ),
                                            Container(
                                                width=300,
                                                bgcolor=colors.GREEN,
                                                border_radius=border_radius.all(
                                                    20),
                                                padding=20,
                                                content=Column(
                                                    controls=[
                                                        ElevatedButton(
                                                            text="Play again",
                                                            bgcolor=colors.BLUE_GREY_100,

                                                            color=colors.BLACK,
                                                            on_click=lambda _: page.go(
                                                                "/"),
                                                        ),
                                                        ElevatedButton(
                                                            text="exit",
                                                            bgcolor=colors.RED,
                                                            color=colors.BLACK,
                                                            on_click=exit,
                                                        ),
                                                    ]
                                                )
                                            ),
                                        ]
                                    )
                                )
                            ]
                        )
                    ],
                )
            )
        page.update()

    page.on_route_change = route_change
    page.go(page.route)


flet.app(target=main)
