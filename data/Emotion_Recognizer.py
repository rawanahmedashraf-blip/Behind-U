import json
import cloudinary
import requests
import cloudinary.uploader


def upload(imageURL):
    cloudinary.config(
        cloud_name="dfehchjmf",
        api_key="529222792259839",
        api_secret="TeyRTj4xxcmHaly7ju_oh9TA7_Y",
        secure=True
    )
    data = cloudinary.uploader.upload(imageURL)["url"]
    return data


def recognizer(IMGUrl):
    urll = upload(IMGUrl)

    url = "https://emotion-detection2.p.rapidapi.com/emotion-detection"

    payload = "{\r\"url\": \"%s\"\r}" % (urll)
    headers = {
        'content-type': "application/json",
        'x-rapidapi-host': "emotion-detection2.p.rapidapi.com",
        'x-rapidapi-key': "a74bf07708mshe2753096dd4b303p130c57jsn6e957211b926"
    }

    response = requests.request("POST", url, data=payload, headers=headers)
    try:
        print("The person is: " +
              str(json.loads(response.text)[0]["emotion"]["value"]))
    except KeyError:
        pass
