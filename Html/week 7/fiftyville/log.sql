-- Keep a log of any SQL queries you execute as you solve the mystery.

.table
airports              crime_scene_reports   people
atm_transactions      flights               phone_calls
bakery_security_logs  interviews
bank_accounts         passenger

SELECT * FROM crime_scene_reports WHERE street = "Humphrey Street" AND day = 28 AND month = 7 AND year = 2023;
+-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| id  | year | month | day |     street      |                                                                                                       description                                                                                                        |
+-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| 295 | 2023 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
| 297 | 2023 | 7     | 28  | Humphrey Street | Littering took place at 16:36. No known witnesses.                                                                                                                                                                       |
+-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

SELECT * FROM interviews WHERE transcript LIKE '%bakery%' AND day = 28 AND month = 7 AND year = 2023;
+-----+---------+------+-------+-----+--------------------------------------------------------------+
| id  |  name   | year | month | day |                          transcript                          |
+-----+---------+------+-------+-----+--------------------------------------------------------------+
| 161 | Ruth    | 2023 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief ge |
|     |         |      |       |     | t into a car in the bakery parking lot and drive away. If yo |
|     |         |      |       |     | u have security footage from the bakery parking lot, you mig |
|     |         |      |       |     | ht want to look for cars that left the parking lot in that t |
|     |         |      |       |     | ime frame.                                                   |
+-----+---------+------+-------+-----+--------------------------------------------------------------+
| 162 | Eugene  | 2023 | 7     | 28  | I don't know the thief's name, but it was someone I recogniz |
|     |         |      |       |     | ed. Earlier this morning, before I arrived at Emma''s bakery, |
|     |         |      |       |     |  I was walking by the ATM on Leggett Street and saw the thie |
|     |         |      |       |     | f there withdrawing some money.                              |
+-----+---------+------+-------+-----+--------------------------------------------------------------+
| 163 | Raymond | 2023 | 7     | 28  | As the thief was leaving the bakery, they called someone who |
|     |         |      |       |     |  talked to them for less than a minute. In the call, I heard |
|     |         |      |       |     |  the thief say that they were planning to take the earliest  |
|     |         |      |       |     | flight out of Fiftyville tomorrow. The thief then asked the  |
|     |         |      |       |     | person on the other end of the phone to purchase the flight  |
|     |         |      |       |     | ticket.                                                      |
+-----+---------+------+-------+-----+--------------------------------------------------------------+

SELECT * FROM bakery_security_logs WHERE hour IN (9,10)  AND day = 28 AND month = 7 AND year = 2023;
+-----+------+-------+-----+------+--------+----------+---------------+
| id  | year | month | day | hour | minute | activity | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+
| 254 | 2023 | 7     | 28  | 9    | 14     | entrance | 4328GD8       |
| 255 | 2023 | 7     | 28  | 9    | 15     | entrance | 5P2BI95       |
| 256 | 2023 | 7     | 28  | 9    | 20     | entrance | 6P58WS2       |
| 257 | 2023 | 7     | 28  | 9    | 28     | entrance | G412CB7       |
| 258 | 2023 | 7     | 28  | 10   | 8      | entrance | R3G7486       |
| 259 | 2023 | 7     | 28  | 10   | 14     | entrance | 13FNH73       |
| 260 | 2023 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
| 261 | 2023 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |SELECT * FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2023 AND duration < 70
| 262 | 2023 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
| 263 | 2023 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 264 | 2023 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
| 265 | 2023 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
| 266 | 2023 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
| 267 | 2023 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
| 268 | 2023 | 7     | 28  | 10   | 35     | exit     | 1106N58       |
| 269 | 2023 | 7     | 28  | 10   | 42     | entrance | NRYN856       |
| 270 | 2023 | 7     | 28  | 10   | 44     | entrance | WD5M8I6       |
| 271 | 2023 | 7     | 28  | 10   | 55     | entrance | V47T75I       |
+-----+------+-------+-----+------+--------+----------+---------------+


SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2023 AND atm_location = "Leggett Street";
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| 246 | 28500762       | 2023 | 7     | 28  | Leggett Street | withdraw         | 48     |
| 264 | 28296815       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 266 | 76054385       | 2023 | 7     | 28  | Leggett Street | withdraw         | 60     |
| 267 | 49610011       | 2023 | 7     | 28  | Leggett Street | withdraw         | 50     |
| 269 | 16153065       | 2023 | 7     | 28  | Leggett Street | withdraw         | 80     |
| 275 | 86363979       | 2023 | 7     | 28  | Leggett Street | deposit          | 10     |
| 288 | 25506511       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 313 | 81061156       | 2023 | 7     | 28  | Leggett Street | withdraw         | 30     |
| 336 | 26013199       | 2023 | 7     | 28  | Leggett Street | withdraw         | 35     |
+-----+----------------+------+-------+-----+----------------+------------------+--------+

SELECT * FROM airports WHERE city = "Fiftyville";
+----+--------------+-----------------------------+------------+
| id | abbreviation |          full_name          |    city    |
+----+--------------+-----------------------------+------------+
| 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
+----+--------------+-----------------------------+------------+


SELECT * FROM flights WHERE day = 29 AND month = 7 AND year = 2023 AND origin_airport_id = 8;
+----+-------------------+------------------------+------+-------+-----+------+--------+
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+----+-------------------+------------------------+------+-------+-----+------+--------+
| 18 | 8                 | 6                      | 2023 | 7     | 29  | 16   | 0      |
| 23 | 8                 | 11                     | 2023 | 7     | 29  | 12   | 15     |
| 36 | 8                 | 4                      | 2023 | 7     | 29  | 8    | 20     |
| 43 | 8                 | 1                      | 2023 | 7     | 29  | 9    | 30     |
| 53 | 8                 | 9                      | 2023 | 7     | 29  | 15   | 20     |
+----+-------------------+------------------------+------+-------+-----+------+--------+


SELECT * FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 AND year
= 2023 AND duration < 60) and license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE hour = 10 AND
day = 28 AND month = 7 AND year = 2023);
+--------+--------+----------------+-----------------+---------------+
|   id   |  name  |  phone_number  | passport_number | license_plate |
+--------+--------+----------------+-----------------+---------------+
| 398010 | Sofia  | (130) 555-0289 | 1695452385      | G412CB7       |
| 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       |
| 514354 | Diana  | (770) 555-1861 | 3592750733      | 322W7JE       |
| 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55       |
| 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+--------+----------------+-----------------+---------------+



SELECT * FROM passengers WHERE passport_number IN(
    SELECT passport_number FROM people WHERE phone_number IN(
        SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2023 AND phone_calls.duration < 60
    )
    and license_plate IN (
        SELECT license_plate FROM bakery_security_logs WHERE hour = 10 AND day = 28 AND month = 7 AND year = 2023
    )
)
AND flight_id IN (
    SELECT flights.id FROM flights WHERE day = 29 AND month = 7
    AND year = 2023 AND origin_airport_id = 8
);
+-----------+-----------------+------+
| flight_id | passport_number | seat |
+-----------+-----------------+------+
| 18        | 3592750733      | 4C   |
| 36        | 1695452385      | 3B   |
| 36        | 5773159633      | 4A   |
| 36        | 8294398571      | 6C   |
| 36        | 1988161715      | 6D   |
+-----------+-----------------+------+

SELECT * FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2023 AND caller = '(770) 555-1861';
+-----+----------------+----------------+------+-------+-----+----------+
| id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 255 | (770) 555-1861 | (725) 555-3243 | 2023 | 7     | 28  | 49       |
+-----+----------------+----------------+------+-------+-----+----------+

SELECT * FROM people WHERE phone_number IN ('(725) 555-3243','(770) 555-1861');
+--------+--------+----------------+-----------------+---------------+
|   id   |  name  |  phone_number  | passport_number | license_plate |
+--------+--------+----------------+-----------------+---------------+
| 847116 | Philip | (725) 555-3243 | 3391710505      | GW362R6       |
| 514354 | Diana  | (770) 555-1861 | 3592750733      | 322W7JE       |
+--------+-------+----------------+-----------------+----------------+

SELECT * FROM  people WHERE phone_number IN ('(367) 555-5533','(375) 555-8161');
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
| 864400 | Robin | (375) 555-8161 | NULL            | 4V16VO0       |
+--------+-------+----------------+-----------------+---------------+

SELECT * FROM bank_accounts WHERE bank_accounts.account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND
year = 2023 AND atm_location = "Leggett Street");
+----------------+-----------+---------------+
| account_number | person_id | creation_year |
+----------------+-----------+---------------+
| 49610011       | 686048    | 2010          |
| 86363979       | 948985    | 2010          |
| 26013199       | 514354    | 2012          |
| 16153065       | 458378    | 2012          |
| 28296815       | 395717    | 2014          |
| 25506511       | 396669    | 2014          |
| 28500762       | 467400    | 2014          |
| 76054385       | 449774    | 2015          |
| 81061156       | 438727    | 2018          |
+----------------+-----------+---------------+

