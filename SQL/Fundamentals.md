# Database Fundamentals — SQL, NoSQL, MongoDB, Security & Interview Prep

A practical reference for interns and job applicants preparing for database-related roles.

---

## Table of Contents

1. [What Is a Database?](#1-what-is-a-database)
2. [SQL vs NoSQL — Short Comparison](#2-sql-vs-nosql--short-comparison)
3. [SQL Fundamentals](#3-sql-fundamentals)
4. [MongoDB & NoSQL Fundamentals](#4-mongodb--nosql-fundamentals)
5. [Database Systems Concepts](#5-database-systems-concepts)
6. [Security Essentials](#6-security-essentials)
7. [Learning Roadmap (Intern / Job Applicant)](#7-learning-roadmap-intern--job-applicant)
8. [Comprehensive Topic Checklist](#8-comprehensive-topic-checklist)
9. [Interview Questions & Answers](#9-interview-questions--answers)

---

## 1. What Is a Database?

A **database** is an organized collection of structured or semi-structured data stored electronically. A **Database Management System (DBMS)** is software that creates, manages, and queries that data (e.g., PostgreSQL, MySQL, MongoDB).

**Why databases matter in software jobs:**
- Almost every application stores users, orders, logs, or configs in a database.
- Backend developers read/write data daily.
- Performance, correctness, and security all depend on how you use the DB.

**Core terms:**
| Term | Meaning |
|------|---------|
| **Table (relation)** | Rows and columns in SQL |
| **Row (record/tuple)** | One entry in a table |
| **Column (field/attribute)** | One property of a record |
| **Primary Key (PK)** | Uniquely identifies each row |
| **Foreign Key (FK)** | References a PK in another table |
| **Schema** | Structure/definition of tables and relationships |
| **Query** | Request to read or modify data |
| **Index** | Data structure to speed up lookups |
| **Transaction** | Group of operations that succeed or fail together |

---

## 2. SQL vs NoSQL — Short Comparison

### SQL (Relational Databases)

**Examples:** PostgreSQL, MySQL, SQLite, SQL Server, Oracle

- Data stored in **tables** with fixed columns and rows.
- Uses **SQL** (Structured Query Language) for queries.
- **Schema-first:** structure is defined before inserting data.
- Strong **relationships** via foreign keys.
- **ACID transactions** (Atomicity, Consistency, Isolation, Durability).
- Best for: financial systems, e-commerce, reporting, structured business data.

### NoSQL (Non-Relational Databases)

**Examples:** MongoDB (document), Redis (key-value), Cassandra (wide-column), Neo4j (graph)

- Flexible or schema-less data models.
- Optimized for **scale, speed, or specific data shapes**.
- Often **horizontal scaling** (sharding across servers).
- Trade-offs in consistency vs availability (CAP theorem).
- Best for: real-time apps, large unstructured data, caching, IoT, rapid prototyping.

### Quick Comparison Table

| Feature | SQL | NoSQL |
|---------|-----|-------|
| Data model | Tables (rows/columns) | Documents, key-value, graph, etc. |
| Schema | Fixed, enforced | Flexible / dynamic |
| Scaling | Mostly vertical; replication | Horizontal sharding common |
| Joins | Native JOIN support | Often denormalized or app-side joins |
| Transactions | Full ACID (most engines) | Varies by DB |
| Query language | SQL | DB-specific (e.g., MongoDB query API) |
| Examples | PostgreSQL, MySQL | MongoDB, Redis, Cassandra |

**Interview one-liner:**  
*"SQL is best when data is structured and relationships matter. NoSQL fits flexible schemas, high write throughput, or when you need to scale out quickly — choose based on use case, not hype."*

---

## 3. SQL Fundamentals

### 3.1 Categories of SQL Commands

| Category | Purpose | Examples |
|----------|---------|----------|
| **DDL** (Data Definition Language) | Define/modify structure | `CREATE`, `ALTER`, `DROP`, `TRUNCATE` |
| **DML** (Data Manipulation Language) | Manipulate data | `SELECT`, `INSERT`, `UPDATE`, `DELETE` |
| **DCL** (Data Control Language) | Permissions | `GRANT`, `REVOKE` |
| **TCL** (Transaction Control Language) | Transaction management | `COMMIT`, `ROLLBACK`, `SAVEPOINT` |

### 3.2 Creating Tables

```sql
CREATE TABLE employees (
    id          INT PRIMARY KEY AUTO_INCREMENT,
    name        VARCHAR(100) NOT NULL,
    email       VARCHAR(255) UNIQUE,
    department  VARCHAR(50),
    salary      DECIMAL(10, 2),
    hired_at    DATE DEFAULT CURRENT_DATE
);
```

### 3.3 Basic Queries (SELECT)

```sql
-- Select all columns
SELECT * FROM employees;

-- Select specific columns with filter
SELECT name, salary FROM employees WHERE department = 'Engineering';

-- Sorting
SELECT name, salary FROM employees ORDER BY salary DESC;

-- Limit results
SELECT name FROM employees LIMIT 10 OFFSET 20;  -- pagination
```

### 3.4 Filtering (WHERE)

```sql
SELECT * FROM employees
WHERE salary > 50000
  AND department = 'Sales'
  AND hired_at >= '2023-01-01';

-- IN, BETWEEN, LIKE, IS NULL
SELECT * FROM products WHERE category IN ('Electronics', 'Books');
SELECT * FROM orders WHERE total BETWEEN 100 AND 500;
SELECT * FROM users WHERE email LIKE '%@gmail.com';
SELECT * FROM users WHERE phone IS NULL;
```

### 3.5 Aggregations (GROUP BY, HAVING)

```sql
SELECT department, COUNT(*) AS headcount, AVG(salary) AS avg_salary
FROM employees
GROUP BY department
HAVING AVG(salary) > 60000;
```

**Rule:** Columns in `SELECT` must be in `GROUP BY` or inside an aggregate function.

### 3.6 Joins

```sql
-- INNER JOIN: only matching rows
SELECT e.name, d.dept_name
FROM employees e
INNER JOIN departments d ON e.department_id = d.id;

-- LEFT JOIN: all rows from left table
SELECT c.name, o.order_id
FROM customers c
LEFT JOIN orders o ON c.id = o.customer_id;

-- RIGHT JOIN, FULL OUTER JOIN (PostgreSQL supports FULL)
-- SELF JOIN
SELECT a.name AS employee, b.name AS manager
FROM employees a
JOIN employees b ON a.manager_id = b.id;
```

**Join types to know:**
- **INNER JOIN** — intersection of both tables
- **LEFT JOIN** — all from left + matches from right
- **RIGHT JOIN** — all from right + matches from left
- **FULL OUTER JOIN** — all rows from both
- **CROSS JOIN** — Cartesian product

### 3.7 Subqueries

```sql
-- Subquery in WHERE
SELECT name FROM employees
WHERE salary > (SELECT AVG(salary) FROM employees);

-- Subquery in FROM (derived table)
SELECT dept, avg_sal FROM (
    SELECT department AS dept, AVG(salary) AS avg_sal
    FROM employees GROUP BY department
) AS stats;
```

### 3.8 INSERT, UPDATE, DELETE

```sql
INSERT INTO employees (name, email, salary) VALUES ('Alice', 'alice@co.com', 75000);

UPDATE employees SET salary = salary * 1.1 WHERE department = 'Engineering';

DELETE FROM employees WHERE hired_at < '2020-01-01';
```

### 3.9 Constraints

```sql
CREATE TABLE orders (
    id           INT PRIMARY KEY,
    customer_id  INT NOT NULL,
    total        DECIMAL(10,2) CHECK (total >= 0),
    status       VARCHAR(20) DEFAULT 'pending',
    FOREIGN KEY (customer_id) REFERENCES customers(id)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);
```

**Constraint types:** `PRIMARY KEY`, `FOREIGN KEY`, `UNIQUE`, `NOT NULL`, `CHECK`, `DEFAULT`

### 3.10 Indexes

```sql
CREATE INDEX idx_employees_email ON employees(email);
CREATE UNIQUE INDEX idx_users_username ON users(username);
```

**Why indexes matter:** Speed up `WHERE`, `JOIN`, and `ORDER BY` — at the cost of slower writes and extra storage.

**When to index:** columns used frequently in filters, joins, or sorting.

### 3.11 Views

```sql
CREATE VIEW active_employees AS
SELECT id, name, department FROM employees WHERE status = 'active';

SELECT * FROM active_employees;
```

A view is a saved query — useful for security and simplifying complex queries.

### 3.12 Normalization (1NF → 3NF)

| Normal Form | Rule |
|-------------|------|
| **1NF** | Atomic values; no repeating groups |
| **2NF** | 1NF + no partial dependency on composite PK |
| **3NF** | 2NF + no transitive dependency (non-key → non-key) |

**Denormalization:** Intentionally breaking normal forms for read performance (common in analytics).

### 3.13 Transactions

```sql
START TRANSACTION;

UPDATE accounts SET balance = balance - 100 WHERE id = 1;
UPDATE accounts SET balance = balance + 100 WHERE id = 2;

COMMIT;   -- save changes
-- ROLLBACK;  -- undo if error
```

**ACID:**
- **Atomicity** — all or nothing
- **Consistency** — valid state before and after
- **Isolation** — concurrent transactions don't interfere incorrectly
- **Durability** — committed data survives crashes

### 3.14 Isolation Levels (Know for Interviews)

| Level | Dirty Read | Non-Repeatable Read | Phantom Read |
|-------|------------|---------------------|--------------|
| READ UNCOMMITTED | Yes | Yes | Yes |
| READ COMMITTED | No | Yes | Yes |
| REPEATABLE READ | No | No | Yes |
| SERIALIZABLE | No | No | No |

---

## 4. MongoDB & NoSQL Fundamentals

### 4.1 Document Model

MongoDB stores data as **BSON documents** (JSON-like) in **collections**.

```json
{
  "_id": ObjectId("..."),
  "name": "Alice",
  "email": "alice@example.com",
  "skills": ["Python", "SQL", "MongoDB"],
  "address": {
    "city": "Colombo",
    "country": "Sri Lanka"
  }
}
```

### 4.2 Basic MongoDB Operations

```javascript
// Insert
db.users.insertOne({ name: "Alice", age: 25 });
db.users.insertMany([{ name: "Bob" }, { name: "Carol" }]);

// Find
db.users.find({ age: { $gte: 18 } });
db.users.findOne({ name: "Alice" });

// Update
db.users.updateOne(
  { name: "Alice" },
  { $set: { age: 26 }, $push: { skills: "Docker" } }
);

// Delete
db.users.deleteOne({ name: "Bob" });
db.users.deleteMany({ status: "inactive" });
```

### 4.3 Query Operators (Know These)

| Operator | Meaning |
|----------|---------|
| `$eq`, `$ne` | Equal / not equal |
| `$gt`, `$gte`, `$lt`, `$lte` | Comparisons |
| `$in`, `$nin` | In / not in array |
| `$and`, `$or`, `$not` | Logical |
| `$exists` | Field exists |
| `$regex` | Pattern match |

### 4.4 Aggregation Pipeline

```javascript
db.orders.aggregate([
  { $match: { status: "completed" } },
  { $group: { _id: "$customerId", totalSpent: { $sum: "$amount" } } },
  { $sort: { totalSpent: -1 } },
  { $limit: 10 }
]);
```

**Stages to know:** `$match`, `$group`, `$project`, `$sort`, `$limit`, `$lookup` (like JOIN), `$unwind`

### 4.5 Indexing in MongoDB

```javascript
db.users.createIndex({ email: 1 }, { unique: true });
db.orders.createIndex({ customerId: 1, createdAt: -1 });
```

### 4.6 When to Choose MongoDB

**Good fit:**
- Flexible/evolving schema
- Nested/hierarchical documents
- High write throughput
- Rapid prototyping

**Poor fit:**
- Complex multi-table joins
- Strict ACID across many entities
- Heavy reporting with relational logic

---

## 5. Database Systems Concepts

### 5.1 Architecture Layers

```
Application → ORM/Query Layer → DBMS → Storage Engine → Disk
```

### 5.2 Connection Pooling

Reuse DB connections instead of opening a new one per request. Libraries: HikariCP (Java), pg pool (Node), SQLAlchemy pool (Python).

### 5.3 Replication

- **Primary-Replica (Master-Slave):** Writes to primary; reads from replicas.
- **Failover:** Promote replica if primary fails.

### 5.4 Sharding (Horizontal Partitioning)

Split data across multiple servers by a **shard key** (e.g., `user_id`).

### 5.5 CAP Theorem

In a distributed system, you can fully guarantee at most **two** of:
- **C**onsistency — every read gets latest write
- **A**vailability — every request gets a response
- **P**artition tolerance — system works despite network splits

### 5.6 ORMs (Object-Relational Mappers)

| Language | ORM Examples |
|----------|--------------|
| Python | SQLAlchemy, Django ORM |
| Java | Hibernate, JPA |
| Node.js | Prisma, Sequelize, TypeORM |
| C# | Entity Framework |

**Pros:** Faster development, less raw SQL.  
**Cons:** N+1 queries, performance surprises — know the generated SQL.

### 5.7 N+1 Query Problem

Loading 100 users, then running 1 query per user for orders = 101 queries.

**Fix:** Use JOIN or eager loading (`JOIN FETCH`, `select_related`, `include`).

### 5.8 Migrations

Version-controlled schema changes (Flyway, Liquibase, Alembic, Prisma Migrate).

---

## 6. Security Essentials

### 6.1 SQL Injection — What It Is

**SQL Injection** happens when user input is concatenated into SQL queries, letting attackers run malicious SQL.

**Vulnerable code (NEVER do this):**
```python
query = f"SELECT * FROM users WHERE username = '{username}' AND password = '{password}'"
```

**Attack input:**
```
username: admin' --
password: anything
```

**Resulting query:**
```sql
SELECT * FROM users WHERE username = 'admin' --' AND password = 'anything'
```
The `--` comments out the password check → attacker logs in as admin.

### 6.2 How to Prevent SQL Injection

| Method | Description |
|--------|-------------|
| **Parameterized queries / prepared statements** | DB treats input as data, not code |
| **ORMs with parameter binding** | ORM handles escaping |
| **Input validation** | Whitelist allowed formats |
| **Least privilege** | DB user should not have DROP/ADMIN rights |
| **Never expose DB errors to users** | Prevents schema leakage |

**Safe code (Python example):**
```python
cursor.execute(
    "SELECT * FROM users WHERE username = %s AND password = %s",
    (username, password)
)
```

**Safe code (Node.js):**
```javascript
db.query('SELECT * FROM users WHERE id = ?', [userId]);
```

### 6.3 Other Database Security Topics

| Topic | What to Know |
|-------|--------------|
| **Authentication** | Strong passwords, no default accounts |
| **Authorization (RBAC)** | Role-based access: read-only vs admin |
| **Encryption at rest** | Data encrypted on disk |
| **Encryption in transit** | TLS/SSL for connections |
| **Audit logging** | Track who changed what |
| **Backup & recovery** | Regular backups, test restores |
| **NoSQL injection** | Validate/sanitize input in MongoDB queries too |
| **Secrets management** | Never commit DB passwords; use env vars / vaults |

### 6.4 MongoDB Security Basics

```javascript
// BAD — user input in query string evaluation
db.users.find({ $where: "this.name == '" + userInput + "'" });

// GOOD — use operators with typed values
db.users.find({ name: userInput });
```

- Enable authentication (`--auth`)
- Use role-based access control
- Bind to localhost or private network in dev
- Keep MongoDB updated

---

## 7. Learning Roadmap (Intern / Job Applicant)

### Phase 1 — Foundations (Week 1–2)
- [ ] Install PostgreSQL or MySQL locally
- [ ] Learn SELECT, WHERE, ORDER BY, LIMIT
- [ ] Learn INSERT, UPDATE, DELETE
- [ ] Understand PK, FK, constraints
- [ ] Practice on SQLBolt, LeetCode SQL, HackerRank SQL

### Phase 2 — Intermediate SQL (Week 3–4)
- [ ] JOINs (INNER, LEFT, RIGHT)
- [ ] GROUP BY, HAVING, aggregate functions
- [ ] Subqueries and CTEs (`WITH`)
- [ ] Indexes — when and why
- [ ] Normalization basics

### Phase 3 — MongoDB (Week 5)
- [ ] Install MongoDB / use MongoDB Atlas (free tier)
- [ ] CRUD operations
- [ ] Query operators and aggregation pipeline
- [ ] Indexing basics
- [ ] Compare SQL vs MongoDB for same use case

### Phase 4 — Systems & Security (Week 6)
- [ ] ACID, transactions, isolation levels
- [ ] SQL injection — attack and defend
- [ ] Connection pooling, ORMs
- [ ] Replication and backup concepts
- [ ] Read about CAP theorem

### Phase 5 — Interview Prep (Ongoing)
- [ ] Solve 20+ SQL practice problems
- [ ] Build a small project with DB (e.g., todo app with PostgreSQL + REST API)
- [ ] Review interview Q&A below
- [ ] Be ready to explain a schema you designed

---

## 8. Comprehensive Topic Checklist

### SQL Must-Know
- [ ] SELECT, INSERT, UPDATE, DELETE
- [ ] WHERE, AND, OR, NOT, IN, BETWEEN, LIKE, IS NULL
- [ ] ORDER BY, LIMIT, OFFSET
- [ ] COUNT, SUM, AVG, MIN, MAX
- [ ] GROUP BY, HAVING
- [ ] INNER / LEFT / RIGHT / FULL JOIN
- [ ] Subqueries (scalar, correlated, EXISTS)
- [ ] CTEs (`WITH`)
- [ ] Window functions (`ROW_NUMBER`, `RANK`, `LEAD`, `LAG`) — bonus
- [ ] CREATE TABLE, ALTER TABLE, DROP
- [ ] PRIMARY KEY, FOREIGN KEY, UNIQUE, CHECK, NOT NULL
- [ ] Indexes (B-tree basics)
- [ ] Views
- [ ] Transactions: COMMIT, ROLLBACK
- [ ] ACID properties
- [ ] Normalization (1NF, 2NF, 3NF)
- [ ] EXPLAIN / query plans (basics)

### MongoDB Must-Know
- [ ] Collections, documents, `_id`
- [ ] insertOne, insertMany, find, findOne
- [ ] updateOne, updateMany, deleteOne, deleteMany
- [ ] Query operators ($gt, $in, $and, $or, $regex)
- [ ] Projection (select fields)
- [ ] $set, $push, $pull, $inc update operators
- [ ] createIndex, explain()
- [ ] Aggregation: $match, $group, $project, $sort, $lookup
- [ ] Embedded vs referenced documents
- [ ] Schema design patterns (embedding vs referencing)

### Database Systems Must-Know
- [ ] DBMS vs file system
- [ ] Schema vs instance
- [ ] Primary vs secondary storage
- [ ] Buffer pool / caching
- [ ] Write-ahead logging (WAL)
- [ ] Locking and concurrency
- [ ] Deadlocks
- [ ] Replication (primary-replica)
- [ ] Sharding / partitioning
- [ ] Backup strategies (full, incremental)
- [ ] ORMs and migrations
- [ ] N+1 problem
- [ ] Connection pooling

### Security Must-Know
- [ ] SQL injection — cause and prevention
- [ ] Parameterized queries
- [ ] Principle of least privilege
- [ ] Password hashing (bcrypt, argon2) — not DB-specific but related
- [ ] TLS for DB connections
- [ ] Environment variables for secrets
- [ ] NoSQL injection awareness
- [ ] OWASP Top 10 (Injection is #3)

---

## 9. Interview Questions & Answers

### SQL Basics

**Q1: What is the difference between DELETE, TRUNCATE, and DROP?**

| Command | What it does | Rollback? | Triggers? |
|---------|--------------|-----------|-----------|
| DELETE | Removes rows (can use WHERE) | Yes (in transaction) | Fires |
| TRUNCATE | Removes all rows, keeps table | Depends on DB | Usually no |
| DROP | Removes entire table | No | N/A |

---

**Q2: What is the difference between WHERE and HAVING?**

- **WHERE** filters rows **before** grouping.
- **HAVING** filters groups **after** `GROUP BY`.
- `WHERE` cannot use aggregate functions; `HAVING` can.

```sql
SELECT department, AVG(salary)
FROM employees
WHERE status = 'active'       -- filter rows first
GROUP BY department
HAVING AVG(salary) > 50000;   -- filter groups
```

---

**Q3: Explain INNER JOIN vs LEFT JOIN.**

- **INNER JOIN:** Returns only rows with matching keys in both tables.
- **LEFT JOIN:** Returns all rows from the left table; unmatched right columns are NULL.

Example: All customers and their orders (including customers with no orders) → **LEFT JOIN** from customers to orders.

---

**Q4: What is a primary key vs a foreign key?**

- **Primary key:** Uniquely identifies each row in a table. One per table (can be composite).
- **Foreign key:** Column(s) that reference a primary key in another table, enforcing referential integrity.

---

**Q5: What is normalization and why do we use it?**

Normalization organizes data to **reduce redundancy** and **avoid update anomalies**. 1NF ensures atomic values; 2NF removes partial dependencies; 3NF removes transitive dependencies. We denormalize when read performance is more important than storage efficiency.

---

**Q6: What is an index and when should you create one?**

An index is a data structure (usually B-tree) that speeds up data retrieval. Create indexes on columns frequently used in `WHERE`, `JOIN`, and `ORDER BY`. Avoid over-indexing — each index slows writes and uses disk space.

---

**Q7: Write a query to find the second highest salary.**

```sql
-- Method 1: Subquery
SELECT MAX(salary) FROM employees
WHERE salary < (SELECT MAX(salary) FROM employees);

-- Method 2: LIMIT/OFFSET (MySQL/PostgreSQL)
SELECT DISTINCT salary FROM employees
ORDER BY salary DESC
LIMIT 1 OFFSET 1;

-- Method 3: Window function
SELECT salary FROM (
    SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
    FROM employees
) t WHERE rnk = 2;
```

---

**Q8: What are ACID properties?**

- **Atomicity:** Transaction completes fully or not at all.
- **Consistency:** Database moves from one valid state to another.
- **Isolation:** Concurrent transactions don't see each other's uncommitted changes incorrectly.
- **Durability:** Committed data persists after system failure.

---

**Q9: What is a correlated subquery?**

A subquery that references the outer query. It runs once per row of the outer query.

```sql
SELECT name, salary FROM employees e
WHERE salary > (
    SELECT AVG(salary) FROM employees WHERE department = e.department
);
```

---

**Q10: Find duplicate emails in a users table.**

```sql
SELECT email, COUNT(*) AS cnt
FROM users
GROUP BY email
HAVING COUNT(*) > 1;
```

---

### SQL vs NoSQL

**Q11: When would you choose SQL over NoSQL?**

Choose SQL when:
- Data is highly structured with clear relationships
- You need complex joins and transactions (ACID)
- Data integrity is critical (banking, inventory)
- You need standardized reporting

---

**Q12: When would you choose MongoDB over PostgreSQL?**

Choose MongoDB when:
- Schema changes frequently
- Data is naturally hierarchical/document-shaped
- You need horizontal scaling for writes
- You don't need complex multi-table joins

---

### MongoDB

**Q13: What is the difference between SQL tables and MongoDB collections?**

SQL tables have a fixed schema with rows and columns. MongoDB collections hold flexible documents (JSON-like) where each document can have different fields.

---

**Q14: How do you model relationships in MongoDB?**

Two approaches:
1. **Embedding** — nest related data inside the document (1-to-few, data read together).
2. **Referencing** — store ObjectId reference (1-to-many, data updated independently).

---

**Q15: What is the aggregation pipeline?**

A framework to process documents through stages (`$match`, `$group`, `$project`, etc.), similar to a SQL query pipeline. Used for analytics and transformations.

---

### Security

**Q16: What is SQL injection and how do you prevent it?**

SQL injection is when attacker-controlled input alters SQL query logic. Prevent with:
1. **Parameterized queries** (prepared statements)
2. **ORMs** with proper parameter binding
3. **Input validation**
4. **Least privilege** DB accounts
5. Never concatenate user input into SQL strings

---

**Q17: Is NoSQL immune to injection attacks?**

No. MongoDB can suffer from **NoSQL injection** if user input is passed unsafely into `$where` clauses or JavaScript evaluation. Always validate input and use typed query operators.

---

**Q18: Why should the application DB user not have admin privileges?**

If the app is compromised via injection, an admin account lets attackers drop tables, read all data, or create backdoor users. Least privilege limits blast radius.

---

### System Design / Advanced

**Q19: What is the N+1 query problem?**

Fetching a list of N records, then running 1 additional query per record to fetch related data (total N+1 queries). Fix with JOINs or eager loading.

---

**Q20: What is a database transaction isolation level?**

Controls how much one transaction sees of another's uncommitted changes. Higher isolation = more consistency, less concurrency. `READ COMMITTED` is common default; `SERIALIZABLE` is strictest.

---

**Q21: What is sharding?**

Splitting data horizontally across multiple database servers using a shard key. Each shard holds a subset of data, enabling scale beyond one machine.

---

**Q22: What is the CAP theorem?**

In distributed systems under network partition, you choose between strong consistency and availability. Most distributed DBs pick AP (availability + partition tolerance) or CP (consistency + partition tolerance).

---

**Q23: How do you optimize a slow SQL query?**

1. Run `EXPLAIN` / `EXPLAIN ANALYZE`
2. Add indexes on filtered/joined columns
3. Avoid `SELECT *`
4. Rewrite subqueries as JOINs if faster
5. Check for N+1 in application code
6. Consider denormalization for read-heavy workloads

---

**Q24: What is a database migration?**

A version-controlled, incremental change to database schema (add column, create table). Tools: Flyway, Liquibase, Alembic, Prisma Migrate. Ensures all environments stay in sync.

---

**Q25: Design a schema for a library system (tables and relationships).**

```sql
CREATE TABLE authors (
    id   INT PRIMARY KEY,
    name VARCHAR(100) NOT NULL
);

CREATE TABLE books (
    id        INT PRIMARY KEY,
    title     VARCHAR(200) NOT NULL,
    author_id INT NOT NULL,
    isbn      VARCHAR(20) UNIQUE,
    FOREIGN KEY (author_id) REFERENCES authors(id)
);

CREATE TABLE members (
    id    INT PRIMARY KEY,
    name  VARCHAR(100) NOT NULL,
    email VARCHAR(255) UNIQUE
);

CREATE TABLE loans (
    id         INT PRIMARY KEY,
    book_id    INT NOT NULL,
    member_id  INT NOT NULL,
    loan_date  DATE NOT NULL,
    return_date DATE,
    FOREIGN KEY (book_id) REFERENCES books(id),
    FOREIGN KEY (member_id) REFERENCES members(id)
);
```

Explain: books belong to authors (1-to-many), members borrow books via loans (many-to-many through junction table).

---

## Quick Reference — SQL Cheat Sheet

```sql
-- Create
CREATE TABLE t (id INT PRIMARY KEY, name VARCHAR(50));

-- Read
SELECT col1, col2 FROM t WHERE condition ORDER BY col1 LIMIT 10;

-- Update
UPDATE t SET col1 = 'value' WHERE id = 1;

-- Delete
DELETE FROM t WHERE id = 1;

-- Join
SELECT a.*, b.* FROM a JOIN b ON a.fk = b.id;

-- Aggregate
SELECT col, COUNT(*) FROM t GROUP BY col HAVING COUNT(*) > 1;

-- Transaction
BEGIN; ... COMMIT;  -- or ROLLBACK;
```

---

## Recommended Free Resources

| Resource | URL / Tool |
|----------|------------|
| SQLBolt (interactive tutorials) | sqlbolt.com |
| PostgreSQL docs | postgresql.org/docs |
| MongoDB University (free courses) | learn.mongodb.com |
| LeetCode Database problems | leetcode.com/problemset/database |
| HackerRank SQL | hackerrank.com/domains/sql |
| Use The Index, Luke (indexing) | use-the-index-luke.com |
| OWASP SQL Injection | owasp.org |

---

*Last updated: July 2026 — tailored for intern and junior developer interview preparation.*
