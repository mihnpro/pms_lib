#!/bin/bash

echo "Generating documentation..."

mkdir -p docs/build

# Пример генерации Markdown в HTML с помощью pandoc (если установлен)
for mdfile in docs/*.md; do
    filename=$(basename "$mdfile" .md)
    pandoc "$mdfile" -o "docs/build/${filename}.html"
done

echo "Documentation generated in docs/build/"
