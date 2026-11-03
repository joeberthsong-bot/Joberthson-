print("=" * 50)
print("        STUDENT WEEKLY EXPENSE TRACKER")
print("=" * 50)

expense_history = []

days = [
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
]

while True:
    try:
        weekly_allowance = float(
            input("\nEnter your weekly allowance: ₱")
        )
        if weekly_allowance < 0:
            print("Allowance cannot be negative.")
        else:
            break

    except ValueError:
        print("Please enter a valid amount.")

weekly_balance = weekly_allowance

while True:

    print("\n" + "=" * 50)
    print("                 MAIN MENU")
    print("=" * 50)
    print("1. Add Expense")
    print("2. View Expense History")
    print("3. View Current Balance")
    print("4. Exit")
    print("=" * 50)

    choice = input("Enter your choice: ")

    if choice == "1":
        print("\nChoose the day:")

        for i, day in enumerate(days, start=1):
            print(f"{i}. {day}")

        day_choice = input("\nEnter the day number: ")

        if not day_choice.isdigit():
            print("Invalid day choice.")
            continue

        day_number = int(day_choice)

        if day_number < 1 or day_number > 7:
            print("Invalid day choice.")
            continue

        selected_day = days[day_number - 1]

        print("\n" + "=" * 50)
        print(f"              {selected_day.upper()}")
        print("=" * 50)

        print("\nChoose an expense category:")
        print("1. Transportation")
        print("2. Food")
        print("3. School Expenses")
        print("4. Personal Needs")
        print("5. Exit")

        category_choice = input("\nEnter your choice: ")
        while True:
            if category_choice == "5":

                print(
                    f"\nFinished entering expenses for "
                    f"{selected_day}."
                )

                break

            if weekly_balance <= 0:

                print("\nNo remaining allowance!")
                print(
                    f"Remaining balance: "
                    f"₱{weekly_balance:.2f}"
                )

                category_choice = input(
                    "\nEnter another expense category (1-5): "
                )

                continue

            if category_choice == "1":
                category = "Transportation"

            elif category_choice == "2":
                category = "Food"

            elif category_choice == "3":
                category = "School Expenses"

            elif category_choice == "4":
                category = "Personal Needs"

            else:
                print("Invalid category choice.")

                category_choice = input(
                    "Enter your category choice (1-5): "
                )

                continue

            while True:
                try:

                    expense = float(
                        input(
                            f"Enter amount spent for "
                            f"{category}: ₱"
                        )
                    )
                    if expense <= 0:

                        print(
                            "Expense must be greater than ₱0."
                        )
                        continue
                    break
                except ValueError:

                    print(
                        "Please enter a valid amount."
                    )
            if expense > weekly_balance:

                print("\nInsufficient allowance!")

                print(
                    f"Remaining balance: "
                    f"₱{weekly_balance:.2f}"
                )
              
                category_choice = input(
                    "\nEnter another expense category (1-5): "
                )
                continue
            weekly_balance -= expense

            expense_history.append({
                "day": selected_day,
                "category": category,
                "amount": expense
            })

            print("\nExpense successfully added!")

            print(
                f"Remaining balance: "
                f"₱{weekly_balance:.2f}"
            )

            if weekly_balance <= 0:

                print(
                    "\nYour allowance is now ₱0.00."
                )

                print(
                    "You cannot add another expense."
                )

                category_choice = input(
                    "\nEnter another expense category or Enter(5) for Exit(1-5): "
                )
                continue

            category_choice = input(
                "\nEnter another expense category (1-5): "
            )

    elif choice == "2":

        print("\n" + "=" * 60)
        print("              WEEKLY EXPENSE HISTORY")
        print("=" * 60)

        if not expense_history:

            print("No expenses recorded yet.")

        else:
            total_spent = 0

            for day in days:

                day_expenses = [
                    expense
                    for expense in expense_history
                    if expense["day"] == day
                ]

                if day_expenses:

                    print(f"\n{day}")
                    print("-" * 60)

                    daily_total = 0

                    for expense in day_expenses:

                        print(
                            f"{expense['category']:<30}"
                            f"₱{expense['amount']:>10.2f}"
                        )

                        daily_total += expense["amount"]
                        total_spent += expense["amount"]

                    print("-" * 60)

                    print(
                        f"{'Daily Total':<30}"
                        f"₱{daily_total:>10.2f}"
                    )
            print("\n" + "=" * 60)

            print(
                f"{'Weekly Allowance':<35}"
                f"₱{weekly_allowance:>10.2f}"
            )

            print(
                f"{'Total Expenses':<35}"
                f"₱{total_spent:>10.2f}"
            )

            print(
                f"{'Remaining Balance':<35}"
                f"₱{weekly_balance:>10.2f}"
            )

            print("=" * 60)

    elif choice == "3":

        total_spent = weekly_allowance - weekly_balance

        print("\n" + "=" * 50)
        print("              CURRENT BALANCE")
        print("=" * 50)

        print(
            f"Weekly Allowance : ₱{weekly_allowance:.2f}"
        )

        print(
            f"Total Spent      : ₱{total_spent:.2f}"
        )

        print(
            f"Remaining Balance: ₱{weekly_balance:.2f}"
        )

        print("=" * 50)

    elif choice == "4":

        print("\n" + "=" * 60)
        print("           FINAL WEEKLY EXPENSE REPORT")
        print("=" * 60)

        if not expense_history:
            print("No expenses were recorded this week.")

        else:
            total_spent = 0

            for day in days:

                day_expenses = [
                    expense
                    for expense in expense_history
                    if expense["day"] == day
                ]
                if day_expenses:

                    print(f"\n{day}")
                    print("-" * 60)

                    daily_total = 0
                  
                    for expense in day_expenses:
                        print(
                            f"{expense['category']:<30}"
                            f"₱{expense['amount']:>10.2f}"
                        )
                        daily_total += expense["amount"]
                        total_spent += expense["amount"]
                    print("-" * 60)
                    print(
                        f"{'Daily Total':<30}"
                        f"₱{daily_total:>10.2f}"
                    )
            print("\n" + "=" * 60)
            print(
                f"{'Weekly Allowance':<35}"
                f"₱{weekly_allowance:>10.2f}"
            )
            print(
                f"{'Total Expenses':<35}"
                f"₱{total_spent:>10.2f}"
            )
            print(
                f"{'Remaining Balance':<35}"
                f"₱{weekly_balance:>10.2f}"
            )
            print("=" * 60)
          
        print(
            "\nThank you for using "
            "Student Weekly Expense Tracker!"
        )
        break
      
    else:
        print("Invalid choice. Please try again.")