for i in {1..400}; do
    input_file="Entradas/instancia${i}.txt"
    output_file="Outputs/output${i}.txt"

    ./Output_Mochila.exe < "$input_file" > "$output_file"
    echo "Computada $input_file e salva em $output_file"

    cat "$output_file" >> output.txt
done