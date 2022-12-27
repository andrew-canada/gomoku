"""
Role-Playing Game (RPG)
"""
import random

WEIGHT = 1
INV_WEIGHT_LIMIT = 200


def display_inv(inventory: dict):
    """
    Print the quantity of each item in inventory, a given dictionary

    >>> display_inv(items)
    Inventory:
      101 gold
      1 dagger
      20 wheat
      16 arrow
      Total items: 138
    """

    print("Inventory: ")
    total_items = 0
    for element, number in inventory.items():
        print("  {} {}".format(number, element))
        total_items += number
    print("  Total items: {}".format(total_items))


def add_to_inv(inventory: dict, loot: list):
    """
    Add items from loot, a given list, to inventory, a given dictionary

    >>> add_to_inv(inventory, ["gold", "gold", "dagger", "apple", "dagger"])
    # increases the number of gold by 2, number of dagger by 2, number of apple by 1
    """

    print("\u001b[7m\u001b[1mYou add the loot to your bag...\u001b[0m")
    remaining_spots = INV_WEIGHT_LIMIT - get_weight(inventory)
    for i in range(min(remaining_spots, len(loot))):
        item = loot.pop(0)
        inventory.setdefault(item, 0)
        inventory[item] += 1

    # loot isn't empty -> not all elements taken
    if loot:
        print("\u001b[7m\u001b[1mYou are over encumbered!\u001b[0m")
        print("\u001b[7m\u001b[1mThese items were not added:\u001b[0m")
        for item in loot:
            print(item, end=" ")
        print()


def drop(inventory: dict, item: str, number: int=1):
    """
    Drop number occurrences of item from inventory.
    Remove the item from inventory if number is >= the number of occurrences of item.

    >>> drop(bag, 'wheat')
    # decreases number of wheat by 1
    >>> drop(bag, 'wheat', 10)
    #decreases number of wheat by 10
    """

    if item in inventory:
        if inventory[item] <= number:
            inventory.pop(item)
        else:
            inventory[item] -= number


def get_weight(inventory: dict) -> int:
    """
    Return the total number of elements in inventory, a given dictionary

    inventory = {"apple": 2, "dog": 1}
    >>> get_weight(inventory)
    3
    """

    total = 0
    for number in inventory.values():
        total += number
    return total * WEIGHT


def is_continue(inventory: dict):
    print("\n  enter \u001b[41;1m\u001b[1m\"q\"\u001b[0m to quit")
    print("  enter \u001b[45;1m\u001b[1m\"d\"\u001b[0m to drop items")
    word = input("  press \u001b[1m\u001b[7mEnter\u001b[0m to continue...\n")
    if word == "q":
        print("\nGoodbye!")
        exit(0)
    if word == "d":
        item = input("\nWhat item would you like to drop? ")
        number = int(input("How many would you like to drop? "))
        drop(inventory, item, number)
        print("\n\u001b[7m\u001b[1mYou dropped {} {}\u001b[0m".format(number, item))
        display_inv(inventory)
        print("Current bag weight:", get_weight(inventory))
        print()
        print("\u001b[7m\u001b[1mYou keep walking...\u001b[0m\n")

    return True


def print_items(loot: list):
    print("\u001b[1m", end="")
    for item in loot:
        print(item, end=" ")
    print("\u001b[0m")



def main():
    print("""\u001b[44;1m\u001b[30;1m-+-+-+-+-+-+-
RPG Inventory
-+-+-+-+-+-+-""")
    print("Here's what you have:\u001b[0m\u001b[44;1m\u001b[30m")
    inventory = {"gold": 101, "dagger": 1, "wheat": 70, "arrow": 16}
    display_inv(inventory)
    print("\u001b[30;1mTotal weight: {}".format(get_weight(inventory)))
    print("The capacity of your bag is {}\u001b[0m".format(INV_WEIGHT_LIMIT))

    while is_continue(inventory):
        val = random.randint(1, 5)
        if val == 1:
            print("\u001b[34;1m\u001b[40;1mYou walk for a day without finding anything... \u001b[0m😔")
        elif val == 2:
            slime_loot = ["gold", "cloth", "wheat", "arrow", "silver", "ruby"]
            print("\u001b[32;1m\u001b[40;1mYou encounter a slime! \u001b[0m😬")
            if not is_continue(inventory):
                break
            print("\u001b[1m\u001b[7mYou defeat the slime easily\u001b[0m")
            if not is_continue(inventory):
                break
            print("\u001b[1m\u001b[7mThe slime drops this loot:\u001b[0m")
            print_items(slime_loot)
            if not is_continue(inventory):
                break
            add_to_inv(inventory, slime_loot)
        elif val == 3:
            print("\u001b[35;1m\u001b[40;1mYou find a chest! \u001b[0m😁")
            if not is_continue(inventory):
                break
            chest_loot = ["gold", "tin", "pencil", "orange"]
            print("\u001b[1m\u001b[7mYou find this loot:\u001b[0m")
            print_items(chest_loot)
            if not is_continue(inventory):
                break
            add_to_inv(inventory, chest_loot)
        elif val == 4:
            print("\u001b[33;1m\u001b[40;1mYou encounter a talking potato! \u001b[0m🥔")
            if not is_continue(inventory):
                break
            is_win = random.randint(1, 6)
            if is_win <= 3:
                potato_loot = ["potato", "potato", "potato", "emerald"]
                print("\u001b[1m\u001b[7mYou befriend the potato!\u001b[0m")
                if not is_continue(inventory):
                    break
                print("\u001b[1m\u001b[7mThe potato gives you this gift:\u001b[0m")
                print_items(potato_loot)
                if not is_continue(inventory):
                    break
                add_to_inv(inventory, potato_loot)
            else:
                print("\u001b[1m\u001b[7mThe potato levitates and hits you in the head\u001b[0m")
                if not is_continue(inventory):
                    break
                print("\u001b[1m\u001b[7mThe potato runs away while you are dreaming about potatoes\u001b[0m")
        else:
            print("\u001b[36;1m\u001b[40;1mYou find a ship! \u001b[0m😮")
            if not is_continue(inventory):
                break
            is_broken = random.randint(1, 2)
            if is_broken == 1:
                print("\u001b[1m\u001b[7mYou take the ship to cross the sea!\u001b[0m")
                if not is_continue(inventory):
                    break
                is_capsize = random.randint(1, 2)
                if is_capsize == 1:
                    print("\u001b[1m\u001b[7mThe ship capsizes!\u001b[0m")
                    if not is_continue(inventory):
                        break
                    print("\u001b[1m\u001b[7mYou lose everything in your inventory!\u001b[0m")
                    inventory.clear()
                else:
                    print("\u001b[1m\u001b[7mYou land on the shore of the New World!\u001b[0m")
            else:
                print("\u001b[1m\u001b[7mThere is a hole in the ship...\u001b[0m")
                if not is_continue(inventory):
                    break
                print("\u001b[1m\u001b[7mYou get chased away by a hostile crab\u001b[0m")
                if not is_continue(inventory):
                    break
        print("\n\u001b[1m\u001b[7mYou keep walking...\u001b[0m")

"""
    drop(inventory, 'wheat') 
    display_inv(inventory)
    drop(inventory, 'wheat', 10)
    display_inv(inventory)
    drop(inventory, 'wheat', 10)
    display_inv(inventory)

    print(get_weight(inventory))

    add_to_inv(inventory, ["apple"])
    print(get_weight(inventory))
    drop(inventory, 'apple')
    add_to_inv(inventory, ["apple", "apple"])
    print(get_weight(inventory))
    drop(inventory, 'apple', 2)
    add_to_inv(inventory, ["apple", "apple", "apple"])
    print(get_weight(inventory))
"""

main()