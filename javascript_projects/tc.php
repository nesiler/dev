$client = new SoapClient("https://tckimlik.nvi.gov.tr/Service/KPSPublic.asmx?WSDL");
try {
    $result = $client->TCKimlikNoDogrula([
        'TCKimlikNo' => '33598447384',
        'Ad' => 'MUHAMMED ENES',
        'Soyad' => 'DİLER',
        'DogumYili' => '2001'
    ]);
    if ($result->TCKimlikNoDogrulaResult) {
        echo 'T.C. Kimlik No Doğru';
    } else {
        echo 'T.C. Kimlik No Hatalı';
    }
} catch (Exception $e) {
    echo $e->faultstring;
}