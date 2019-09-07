import { Injectable } from '@angular/core';
import { HttpClient, HttpParams } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class EstudanteService {

  constructor(private _http: HttpClient) { }

  private baseUrl : string = "http://localhost:8080/estudante";

  //vinculo do usuário ativo com a república {{id}}
  solicitarVinculo(id_republica: any) {
    let params = new HttpParams()
      .set("id_republica", id_republica);
    return this._http.post(this.baseUrl + "/vincular", params );
  }
}
