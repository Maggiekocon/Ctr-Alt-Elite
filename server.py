from fastapi import FastAPI
import pandas as pd

app = FastAPI()

leaderboard = pd.read_csv("leaderboard.csv")

@app.get("/userscore")
def read_root(username: str):
    return {"score": leaderboard[leaderboard["username"] == username]["score"]}

@app.get("/leaderboard")
def read_leaderboard():
    output = []
    entry = {}
    for i, row in leaderboard.iterrows():
        entry[row["username"]] = row["score"]
        output.append(entry)
    return {"leaderboard": output}

@app.post("new")
def create_new_entry(username: str, score: int):
    data = {"username": username, "score": score}
    df_format = pd.DataFrame(data)
    leaderboard = pd.concat([leaderboard, df_format], ignore_index=True)

@app.put("update")
def update_item(username: str, score: int):
    data = {"username": username, "score": score}
    leaderboard[leaderboard["username"] == username] = score

@app.delete("delete_data")
def delete_item(username: str):
    mask = leaderboard["username"] != username 
    leaderboard = leaderboard[mask]

