import { Injectable } from '@angular/core';
import { HttpClient, HttpParams } from '@angular/common/http';
import { UrlService } from './default/url.service';

@Injectable({
  providedIn: 'root'
})
export class EstudanteService {

  constructor(private _http: HttpClient, private _url : UrlService) { }

  private baseUrl : string = this._url.baseUrl() + "/estudante";

  //vinculo do usuário ativo com a república {{id}}
  solicitarVinculo(id_republica: any) {
    let params = new HttpParams()
      .set("id_republica", id_republica);
    return this._http.post(this.baseUrl + "/vincular", params);
  }

  save(estudante: any) {
    return this._http.post(this.baseUrl, estudante);
  }
}
