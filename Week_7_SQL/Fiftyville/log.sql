-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Crime Scene Report
SELECT description FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2020 AND street LIKE 'Chamber%';
-- crime happened at 10:15am
-- there were three witnesses interviewed, they mentioned courthouse

-- Interviews
SELECT transcript FROM interviews
WHERE day = 28 AND month = 7 AND year = 2020 AND transcript LIKE '%court%';
-- thief drove away in a car parked in courthouse parking lot
-- thief used ATM on Fifer street
-- thief on phone call less than a minute

-- Destination
SELECT city FROM airports
JOIN flights f on airports.id = f.destination_airport_id
WHERE day = 29 AND month = 7 AND year = 2020 AND city != 'Fiftyville'
ORDER BY hour, minute
LIMIT 1;

-- The Thief
SELECT DISTINCT name FROM people p
JOIN bank_accounts b on p.id = b.person_id
JOIN courthouse_security_logs ch on ch.license_plate = p.license_plate
JOIN atm_transactions at on b.account_number = at.account_number
JOIN passengers pa on p.passport_number = pa.passport_number
JOIN flights f on f.id = pa.flight_id
JOIN airports a on a.id = f.destination_airport_id
JOIN phone_calls ph on ph.caller = p.phone_number
WHERE
    -- check courthouse security footage of parking lot within 10 minutes after crime
    (ch.minute <= 25 AND ch.hour = 10 AND ch.day = 28 AND ch.month = 7 AND ch.year = 2020 AND ch.activity LIKE 'exit')
    AND
    -- check transaction records on Fifer street
    (at.day = 28 AND at.month = 7 AND at.year = 2020 AND at.transaction_type LIKE 'with%' AND at.atm_location LIKE 'Fifer%')
    AND
    -- check possible purchasers of this ticket
    (f.day = 29 AND f.month = 7 AND f.year = 2020 AND f.origin_airport_id = 8 AND a.city = 'London')
    AND
    -- check phone records
    (ph.day = 28 AND ph.month = 7 AND ph.year = 2020 AND ph.duration < 60);

-- The Accomplice
SELECT DISTINCT name FROM people p
JOIN phone_calls ph on ph.receiver = p.phone_number
WHERE day = 28 AND month = 7 AND year = 2020 AND duration < 60 AND ph.caller = (SELECT p.phone_number FROM people p WHERE name = 'Ernest');
