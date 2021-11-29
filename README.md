# Hello ESP32

## Unit-Test

    # Runs NATIVE!!!! Unit-Test
    pio test -e native --verbose

    # Runs Integration-Test
    pio test -e eps32azdev1 --verbose

Konfiguration welcher Test wann verwendet wird erfolgt über die platformio.ini.

    [env:native]
    platform = native

    # Alle files in test die NICHT mit 
    # integration_ beginnen werden für diese Tests verwendet
    test_ignore = integration_*
    
    build_flags = -DNATIVE

Multiple-Mains in Unit-Test sind nicht erlaubt! Sprich - in den Tests darf es nur ein File
mit einem `main()` geben
