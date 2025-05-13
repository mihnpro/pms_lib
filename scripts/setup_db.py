#!/usr/bin/env python3
import sqlite3

def setup_db():
    conn = sqlite3.connect('pms.db')
    c = conn.cursor()

    c.execute('''
    CREATE TABLE IF NOT EXISTS guests (
        id INTEGER PRIMARY KEY,
        name TEXT NOT NULL
    );
    ''')

    c.execute('''
    CREATE TABLE IF NOT EXISTS rooms (
        number INTEGER PRIMARY KEY,
        type TEXT NOT NULL,
        available BOOLEAN NOT NULL
    );
    ''')

    c.execute('''
    CREATE TABLE IF NOT EXISTS bookings (
        id INTEGER PRIMARY KEY,
        guest_id INTEGER,
        room_number INTEGER,
        check_in TEXT,
        check_out TEXT,
        FOREIGN KEY(guest_id) REFERENCES guests(id),
        FOREIGN KEY(room_number) REFERENCES rooms(number)
    );
    ''')

    conn.commit()
    conn.close()
    print("Database setup completed.")

if __name__ == "__main__":
    setup_db()
