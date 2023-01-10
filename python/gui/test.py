import flet as ft

def exit(e):
    control_text = e.control.bgcolor
    print(control_text)

def change_color(e):
    e.control.bgcolor = ft.colors.AMBER_100
    e.page.update()

def main(page : ft.Page):
    page.add(
        ft.Container(
            content=ft.Row(
                controls=[
                    ft.ElevatedButton(
                        text="",
                        bgcolor=ft.colors.BLUE_100,
                        style=ft.ButtonStyle(shape=ft.CircleBorder()),
                        on_click=change_color,
                        data="button clicked",
                    ),
                    ft.Container(
                        width=100,
                        height=100,
                        bgcolor=ft.colors.YELLOW_100,
                        content=ft.ElevatedButton(
                            text="",
                            bgcolor=ft.colors.BLUE_100,
                            style=ft.ButtonStyle(shape=ft.CircleBorder()),
                            on_click=change_color,
                            data="button clicked",
                        ),
                    ),
                    ft.Container(
                        width=100,
                        height=100,
                        bgcolor=ft.colors.YELLOW_100,
                        content=ft.Column(
                            controls=[
                                ft.Container(
                                    width=30,
                                    height=30,
                                    bgcolor=ft.colors.AMBER_300,
                                    content=ft.Text(
                                        "Player 1 Text"
                                    )
                                ),
                                ft.Container(
                                    width=30,
                                    height=30,
                                    bgcolor=ft.colors.AMBER_300,
                                    content=ft.ElevatedButton(
                                        "Player 1 Button"
                                    )
                                ),
                                ft.Container(
                                    width=30,
                                    height=30,
                                    bgcolor=ft.colors.AMBER_300,
                                    content=ft.Checkbox(
                                        label="Unchecked by default checkbox", 
                                        value=False
                                    )
                                ),
                                ft.Container(
                                    width=30,
                                    height=30,
                                    bgcolor=ft.colors.AMBER_300,
                                    content=ft.Text(
                                        "Player 1"
                                    )
                                ),                                                                
                            ]
                        ),
                    ),
                ],
            ),
        ),
    )

ft.app(target=main)
