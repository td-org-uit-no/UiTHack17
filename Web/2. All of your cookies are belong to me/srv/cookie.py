from flask import Flask, render_template, redirect, url_for, request, g, session, abort, make_response
import os
import sqlite3

app = Flask(__name__)
app.config.update(dict(SECRET_KEY=os.urandom(16)))

def connect_db():
    db = sqlite3.connect("file:./inject_me.sql?mode=ro", uri=True)
    db.row_factory = sqlite3.Row
    return db

def get_db():
    if not hasattr(g, 'db'):
        g.db = connect_db()
    return g.db

@app.route("/", methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        db = get_db()
        cur = db.execute("select * from users where username = '{}' and password = '{}'".format(request.form['username'], request.form['password']))
        entries = cur.fetchall()
        if len(entries) > 0:
            resp = make_response(redirect(url_for('get_flag')))
            session['logged_in'] = True
            if int(entries[0][2]) != 1:
                resp.set_cookie('privileged', value=b"false")
            else:
                resp.set_cookie('privileged', value=b"true")
            return resp
        else:
            return redirect(url_for('login'))
    else:
        return render_template('login.html')

@app.route("/flag")
def get_flag():
    if not session.get('logged_in'):
        abort(401)
    if request.cookies.get('privileged') == 'true':
        return "Congratulations - the flag is: UiTHack{securing_cookies_is_paramount}"
    else:
        return "You need a privileged account to view the flag"
