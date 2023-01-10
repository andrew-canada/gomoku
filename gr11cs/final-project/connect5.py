import flet as ft


def main(page: ft.page):
    page.title = "Connect 5"

    def route_change(route):
        page.views.append(
            ft.View(
                "/",
                [
                    ft.AppBar(title=ft.Text("Welcome"),
                              bgcolor=ft.colors.AMBER_100),
                    ft.TextField(label="Player 1, enter your name:"),
                    ft.ElevatedButton(
                        "Continue", on_click=lambda _: page.go("/mainmenu"))
                ]
            )
        )
        if page.route == "/mainmenu":
            page.views.append(
                ft.View(
                    "/mainmenu",
                    [
                        ft.AppBar(title=ft.Text("Main Menu"),
                                  bgcolor=ft.colors.AMBER_100),
                        ft.ElevatedButton(
                            "Play with another human", on_click=lambda _: page.go("/humanmenu")),
                        ft.ElevatedButton(
                            "Play with engine", on_click=lambda _: page.go("/board")),
                    ]
                )
            )
        if page.route == "/humanmenu":
            page.views.append(
                ft.View(
                    "/humanmenu",
                    [
                        ft.AppBar(title=ft.Text("Human Menu"),
                                  bgcolor=ft.colors.AMBER_100),
                        ft.TextField(label="Player 2, enter your name:"),
                        ft.ElevatedButton(
                            "Play!", on_click=lambda _: page.go("/board"))
                    ]
                )
            )
        if page.route == "/board":
            page.views.append(
                ft.View(
                    "/board",
                    [
                        ft.AppBar(title=ft.Text("Board"),
                                  bgcolor=ft.colors.AMBER_100),
                        ft.ElevatedButton(
                            "Back to Main Menu", on_click=lambda _: page.go("/"))
                    ]
                )
            )

        page.update()

    page.on_route_change = route_change
    page.go(page.route)


ft.app(target=main)
