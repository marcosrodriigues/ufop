import { Injectable } from '@angular/core';
import { HttpClient, HttpParams } from '@angular/common/http';
import { UrlService } from './default/url.service';

@Injectable({
  providedIn: 'root'
})
export class RepublicaService {

  constructor(private _http: HttpClient, private _url : UrlService) { }

  private baseUrl: string = this._url.baseUrl() + "/republica";

  findAll() {
    return this._http.get(this.baseUrl);
  }

  findOne(id) {
    return this._http.get(this.baseUrl + '/' + id);
  }

  findByCity(city) {
    return this._http.get(this.baseUrl + "/city/" + city);
  }

  findByUf(uf) {
    return this._http.get(this.baseUrl + "/uf/" + uf);
  }

  findByUfAndCity(uf, city) {
    return this._http.get(this.baseUrl + "/" + uf + "/" + city);
  }

  findMoradores() {
    return this._http.get(this.baseUrl + "/moradores");
  }

  findPendentes() {
    return this._http.get(this.baseUrl + "/pendentes")
  }

  aprovar(morador: any) {
    return this._http.post(this.baseUrl + "/aprovar", morador);
  }
  
  recusar(morador: any) {
    return this._http.post(this.baseUrl + "/recusar/" + morador, {});
  }

  remover(morador: any) {
    return this._http.post(this.baseUrl+"/remover/" + morador.id, {});
  }

  calcularPersonalidade(republica : any) {
    return this._http.post(this.baseUrl + "/personalidade", republica);
  }

  findBySearch(q) {
    return this._http.get(this.baseUrl + "/search/" + q.cidade + "/" + q.carater);
  }
}
