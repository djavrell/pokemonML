open PokemonModel;
let apiLink = "https://www.pokeapi.co";

let pokemonUrl = id => apiLink ++ "/api/v2/pokemon/" ++ string_of_int(id) ++ "/";

let fetcher = (decoder, url, callback) =>
  Js.Promise.(
    Fetch.fetch(url)
    |> then_(Fetch.Response.json)
    |> then_(json =>
         json
         |> decoder
         |> (
           decodedData => {
             callback(Some(decodedData));
             resolve();
           }
         )
       )
    |> ignore
  );

let pokemonFetcher = (url, callback) => fetcher(PokemonModel.pokemon, url, callback);
