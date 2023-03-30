-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find crime scene description
SELECT description FROM crime_scene_reports
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND street = 'Humphrey Street';

-- Get the interviews from the witnesses
SELECT transcript FROM interviews
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND transcript LIKE '%bakery%';

-- Get the account numbers of people who withdrawn money from ATM on Leggett Street
SELECT account_number FROM atm_transactions
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw';

-- Get the license plate number of people who left parking lot after the crime
SELECT license_plate, hour, minute FROM bakery_security_logs
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND activity = 'exit';

-- Find the ID of airport in Fiftyville
SELECT * FROM airports;

-- Find earliest flight from Fiftyville on 29th of July
SELECT * FROM flights
    WHERE origin_airport_id = 8
    AND year = 2021
    AND month = 7
    AND day = 29;

-- Get the passport numbers of passengers on the flight
SELECT passport_number FROM passengers
    WHERE flight_id = 36;

-- Get person id's using bank account numbers
SELECT person_id FROM bank_accounts
    WHERE account_number = 28500762;

-- Find people using ID
SELECT * FROM people
    WHERE id = 449774;

-- Check who had less than 1 minute phone call
SELECT * FROM phone_calls
    WHERE caller = '(286) 555-6063'
    AND year = 2021
    AND month = 7
    AND day = 28;