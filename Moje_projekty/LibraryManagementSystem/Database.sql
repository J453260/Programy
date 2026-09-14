-- 1. Tworzenie bazy danych LibraryDB
IF NOT EXISTS (SELECT name FROM sys.databases WHERE name = 'LibraryDB')
BEGIN
    CREATE DATABASE LibraryDB;
END;
GO

USE LibraryDB;
GO

-- 2. Tworzenie tabeli Books
IF NOT EXISTS (SELECT * FROM sys.tables WHERE name = 'Books')
BEGIN
    CREATE TABLE Books (
        Id INT IDENTITY(1,1) PRIMARY KEY,
        Title NVARCHAR(255) NOT NULL,
        Author NVARCHAR(255) NOT NULL,
        ISBN VARCHAR(20) NOT NULL UNIQUE,
        IsAvailable BIT NOT NULL DEFAULT 1
    );
END;
GO

-- 3. Tworzenie loginu serwera (dla użytkownika Javy)
IF NOT EXISTS (SELECT name FROM sys.server_principals WHERE name = 'library_app')
BEGIN
    CREATE LOGIN library_app WITH PASSWORD = 'TwojeSilneHaslo123!';
END;
GO

-- 4. Tworzenie użytkownika w bazie i nadanie uprawnień
IF NOT EXISTS (SELECT name FROM sys.database_principals WHERE name = 'library_app')
BEGIN
    CREATE USER library_app FOR LOGIN library_app;
END;
GO

ALTER ROLE db_datareader ADD MEMBER library_app;
ALTER ROLE db_datawriter ADD MEMBER library_app;
GO
