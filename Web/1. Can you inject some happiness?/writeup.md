# Can you inject some happiness?

> > Web - 200pts
> 
> I just started doing some web development, and thought it might be a good idea to require users logging in.
> 
> The web service is located at: `138.68.91.213:4242`
> 
> Files: [server directory](./src/)
> 
> [Writeup](./writeup.md)

## Writeup

When you start the web server and access it, you are prompted with a login screen.

This is vulnerable to SQL injection, meaning the login can be bypassed.

Inserting `' OR 1=1; -- ` into the username field will result in the SQL query:

```sql
SELECT * FROM Users WHERE username='' OR 1=1; -- AND password='';
```

In SQL, `--` is a comment, which will make sure the rest of the query will not be executed, simply resulting in

```sql
SELECT * FROM Users WHERE username='' OR 1=1;
```

Returning the first user in the `Users` table, leaving you logged in and displaying the flag:

`UiTHack{super_duper_critical_injection_vulnerabilities}`
