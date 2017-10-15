# All of your cookies are belong to me

> > Web - 300pts
> 
> A good web service must distinguish between an administrator and a regular user.
> 
> The web service is located at: `138.68.91.213:1337`
> 
> Files: [server directory](./src/)

## Writeup

Starting the web server and accessing it, you are prompted with a login screen and a test user.

Logging in, we see that an insecure cookie is set with `privileged` set to `false`.
Because this is a regular cookie without any authentication, we can change it to `true` and the server will believe the value and allow access to the privileged flag page.

Which will yield the flag:

`UiTHack{securing_cookies_is_paramount}`
