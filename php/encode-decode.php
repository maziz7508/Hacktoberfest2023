<?php

function customEncode($text) {
    return base64_encode($text);
}

function customDecode($encodedText) {
    return base64_decode($encodedText);
}

$originalText = "This is a very long text that needs to be encoded into a shorter form.";
$encodedText = customEncode($originalText);
$decodedText = customDecode($encodedText);

echo "Original Text: $originalText<br>";
echo "Encoded Text: $encodedText<br>";
echo "Decoded Text: $decodedText";

?>
