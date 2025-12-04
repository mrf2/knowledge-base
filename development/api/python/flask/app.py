from flask import Flask, request, jsonify
from models import db, User
app = Flask(__name__)
app.config["SQLALCHEMY_DATABASE_URI"] = "sqlite:///database.db"
app.config["SQLALCHEMY_TRACK_MODIFICATIONS"] = False

db.init_app(app)

# Create tables if not exist
with app.app_context():
    db.create_all()

# ------------------------------
# GET /api/users (List all)
# ------------------------------
@app.get("/api/users")
def list_users():
    users = User.query.all()
    return jsonify([u.to_dict() for u in users])


# ------------------------------
# GET /api/users/<id> (Single)
# ------------------------------
@app.get("/api/users/<int:user_id>")
def get_user(user_id):
    user = User.query.get_or_404(user_id)
    return jsonify(user.to_dict())

# ------------------------------
# POST /api/users (Create)
# ------------------------------
@app.post("/api/users")
def create_user():
    data = request.json
    user = User(name=data["name"], email=data["email"])
    db.session.add(user)
    db.session.commit()
    return jsonify(user.to_dict()), 201


# ------------------------------
# PUT /api/users/<id> (Replace)
# ------------------------------
@app.put("/api/users/<int:user_id>")
def replace_user(user_id):
    user = User.query.get_or_404(user_id)
    data = request.json
    user.name = data["name"]
    user.email = data["email"]
    db.session.commit()
    return jsonify(user.to_dict())


# ------------------------------
# DELETE /api/users/<id>
# ------------------------------
@app.delete("/api/users/<int:user_id>")
def delete_user(user_id):
    user = User.query.get_or_404(user_id)
    db.session.delete(user)
    db.session.commit()
    return "", 204

if __name__ == "__main__":
    app.run(debug=True)