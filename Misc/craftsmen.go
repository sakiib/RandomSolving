package main

import (
    "encoding/base64"
    "fmt"
    "net/http"
)

func main() {
    encodedURL := "aHR0cHM6Ly9mb3Jtcy5nbGUvWU5ZXQ0d2NRWHVLNnNwdjU="
    options := []byte("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+/")

    length := len(encodedURL)

    for i := 0; i <= length; i++ {
        for idx := 0; idx < 64; idx++ {
            tempEncoded := encodedURL[:i] + string(options[idx]) + encodedURL[i:]
            decodedURL, _ := base64.URLEncoding.DecodeString(tempEncoded)

            resp, err := http.Get(string(decodedURL))
            if err == nil && resp.StatusCode == http.StatusOK {
                fmt.Println("this URL is valid & exists: ", string(decodedURL))
            }
        }
    }
}
