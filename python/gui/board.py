import logging
import os
from itertools import islice

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
)

# logging.basicConfig(level=logging.INFO)

os.environ["FLET_WS_MAX_MESSAGE_SIZE"] = "8000000"


class GameBoard(UserControl):
    def __init__(self, expand=False, height=500):
        super().__init__()
        if expand:
            self.expand = expand
        else:
            self.height = height

    def build(self):

        # fetch all icon constants from icons.py module
        #icons.CIRCLE_OUTLINED
        #icons.CIRCLE_ROUNDED

        board = GridView(
            expand=1,
            runs_count=7,
            max_extent=150,
            spacing=5,
            run_spacing=5,
            child_aspect_ratio=1,
        )

        def test_click(e):
            icon_key = e.control.data
            e.control.content = Container(
                        content=Column(
                            [
                                Icon(name=icons.CIRCLE_OUTLINED, size=30),
                                Text(
                                    # value=f"{icons.CIRCLE_ROUNDED}",
                                    size=12,
                                    width=100,
                                    height=100,
                                    no_wrap=True,
                                    text_align="center",
                                    color=colors.ON_SURFACE_VARIANT,
                                ),
                            ],
                            spacing=5,
                            alignment="center",
                            horizontal_alignment="center",
                        ),
                        alignment=alignment.center,
                    )
            print("Copy to clipboard:", icon_key)
            self.update()

        def display_board(e):

            self.update()

            for r in range(0, 5):
                for c in range(0, 7):
                    board.controls.append(
                        TextButton(
                            content=Container(
                                content=Column(
                                    [
                                        Icon(name=icons.CIRCLE_ROUNDED, size=30),
                                        Text(
                                            #value=f"{icons.CIRCLE_ROUNDED}",
                                            size=12,
                                            width=100,
                                            height=100,
                                            no_wrap=True,
                                            text_align="center",
                                            color=colors.ON_SURFACE_VARIANT,
                                        ),
                                    ],
                                    spacing=5,
                                    alignment="center",
                                    horizontal_alignment="center",
                                ),
                                alignment=alignment.center,
                            ),
                            on_click=test_click,
                            data="{}|{}".format(r, c),
                        )
                    )

                self.update()

            self.update()

        return Column(
            [
                board,
                ElevatedButton("test!", on_click=display_board)
            ],
            expand=True,
        )


def main(page: Page):
    page.title = "Connect 4"
    page.add(GameBoard(expand=True))


flet.app(target=main)